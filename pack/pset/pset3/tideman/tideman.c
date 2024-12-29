#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX] = {0};

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX] = {false};

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2]; // 组合数算法

int pair_count = 0;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
bool iscycle(int winner, int loser);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;

    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int k = 0; k < candidate_count; k++)
    {
        if (strcmp(name, candidates[k]) == 0)
        {
            ranks[rank] = k;
            return true;
        }
    }

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
            else if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else
                continue;
        }
    }

    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // Bubble sort 'preferences[pairs.winner][pairs.loser]'
    int storage1, storage2;
    for (int i = 0; i < pair_count - 1; i++)
    {
        for (int j = 0; j < pair_count - 1; j++, storage1 = 0, storage2 = 0)
        {
            if (preferences[pairs[j].winner][pairs[j].loser] <
                preferences[pairs[j + 1].winner][pairs[j + 1].loser])
            {
                storage1 = pairs[j].winner;
                storage2 = pairs[j].loser;
                pairs[j].winner = pairs[j + 1].winner;
                pairs[j].loser = pairs[j + 1].loser;
                pairs[j + 1].winner = storage1;
                pairs[j + 1].loser = storage2;
            }
            else
                continue;
        }
    }
}

// Lock pairs into the candidate graph in order, without creating cycle
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;
        if (!iscycle(winner, loser)) // 1. loser 视为新节点
        {
            locked[winner][loser] = true; // 2. 出
        }
    }

    return;
}

// Print the winner of the election
void print_winner(void)
{
    // 遍历每个候选人 j
    for (int j = 0; j < candidate_count; j++)
    {
        bool is_winner = true; // 假设当前候选人是赢家

        // 检查是否有其他候选人 i 击败了 j
        for (int i = 0; i < candidate_count; i++)
        {
            if (locked[i][j]) // 如果有候选人 i 击败了 j
            {
                is_winner = false; // 说明 j 不是胜者
                break;             // 一旦找到就可以跳出内部循环
            }
        }

        // 如果没有其他候选人击败 j，说明 j 是胜者
        if (is_winner)
        {
            printf("%s\n", candidates[j]); // 输出 j 的名字
            return;                        // 找到胜者后就返回
        }
    }
}

// Detect if makes cycle

// 构成一个新circle需要四个条件: 新节点, 进, 出, 小循环
// 我们想连接两个节点(这两个节点分别视为虚拟小循环内节点与新节点)
// 则满足 *新节点* *出* 两个条件
// 若另外两个条件也满足, 则将构成循环

bool iscycle(int winner, int loser)
{
    // base case : create the smallest cycle
    if (locked[loser][winner])
        return true;

    // recursion case :
    for (int i = 0; i < candidate_count; i++)
    { // locked[loser][i] 即为 *进* // 输入winner,i即连接它们即为创建 *小循环*
        // 若条件均满足, 则连接两节点必定会创建循环
        if (locked[loser][i] && iscycle(winner, i))
            return true;
    }

    return false;
}

// 为什么递归使用iscircle函数?
    // 本函数将尝试通过连接两个节点创建小循环 (locked[loser][i])
    // 从而满足大循环创建条件
    // 因此需要检测该小循环是否创建成功
    // 本函数功能就是判断连接两个节点后是否会创建循环
    // 因此再次使用
