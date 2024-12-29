/*
快速排序算法通过多次比较和交换来实现排序，其排序流程如下：
(1)首先设定一个分界值（通常选用数组的第一个数），通过该分界值将数组分成左右两部分。
(2)将大于或等于分界值的数据集中到数组左边，小于分界值的数据集中到数组的右边。
   此时，左边部分中各元素都大于分界值，而右边部分中各元素都小于或等于分界值。
(3)然后，左边和右边的数据可以独立排序。
   对于左侧的数组数据，又可以取一个分界值，将该部分数据分成左右两部分，同样在左边放置较大值，右边放置较小值。
   右侧的数组数据也可以做类似处理。
(4)重复上述过程，可以看出，这是一个递归定义。通过递归将左侧部分排好序后，再递归排好右侧部分的顺序。
   当左、右两个部分各数据排序完成后，整个数组的排序也就完成了。
*/

#include <iostream>
using namespace std;

void Qsort(int arr[], int low, int high)
// 数组索引 index >= low && index <= high
{
    // base case
    if (low >= high)
        return;

    int i = low;        // 设定左游标
    int j = high;       // 设定右游标
    int key = arr[low]; // 设定一个分界(中枢)值

    while (true)
    {
        /*从左向右找比key小的值*/
        while (arr[i] >= key) // 若比key大则游标移动
        {
            i++;
            if (i >= high)
                break;
        }

        /*从右向左找比key大的值*/
        while (arr[j] <= key) // 若比key小则游标移动
        {
            j--;
            if (j <= low)
                break;
        }

        // 比key小的值在比key大的值的右边
        if (i >= j)
            break;

        // 交换i,j对应的值, 使得比key小的值在比key大的值右边
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    // 中枢值与j对应值(即分界线旁首个比中枢值大的值)交换
    // 使得j对应值左侧均比它大, 右侧均比它小
    arr[low] = arr[j];
    arr[j] = key;

    Qsort(arr, low, j - 1);  // 递归将左侧部分排好序
    Qsort(arr, j + 1, high); // 递归将右侧部分排好序
}

int main()
{
    int a[9] = {57, 68, 59, 52, 72, 28, 96, 33, 24};
    Qsort(a, 0, 8);

    for (int i = 0; i < 9; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
