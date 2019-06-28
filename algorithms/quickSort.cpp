//
// Created by 帆桥 on 2019/6/27.
//

#include "Utils/Vector.hpp"
#include "Utils/optimizeHelp.hpp"
using T = Util::Vector<std::pair<std::string, int>>;

void quicksortByPair(T& a, int left, int right)
{
    if (left < right)                               //递归条件
    {
        int l = left;
        int r = right;
        std::string key = a[left].first;
        auto temp = a[left];
        while (l < r)
        {
            while (l < r&&a[r].first >= key)      //右边界值不小于关键字且右边界位置没有越过左边界位置，保持右边界左移
            {
                r--;
            }a[l] = a[r];                   //直至右边界小于关键字时，将左边界值用右边界值覆盖(如果遇到另一情况，左右边界位置相等时，该赋值语句并无实用）
            while (l < r&&a[l].first <= key)      //同理，左边界值不大于关键字且左边界位置没有越过右边界位置，保持左边界右移
            {
                l++;
            }a[r] = a[l];                   //同理，将右边界值用左边界值覆盖
        }                                       //整个循环结束后，左右边界应指向同一处
        a[l] = temp;                             //将关键字覆盖到边界同时所指的位置，此时关键字左边的全部不比他大，右边的全部不比它小
        quicksortByPair(a, left, l - 1);              //递归
        quicksortByPair(a, l + 1, right);
    }
}

void quickSort(Utilt::distance* arr, int left, int right) {
    if (left < right)                               //递归条件
    {
        int l = left;
        int r = right;
        int key = arr[left].getDist();
        auto temp = arr[left];
        while (l < r)
        {
            while (l < r&&arr[r].getDist() >= key)      //右边界值不小于关键字且右边界位置没有越过左边界位置，保持右边界左移
            {
                r--;
            }arr[l] = arr[r];                   //直至右边界小于关键字时，将左边界值用右边界值覆盖(如果遇到另一情况，左右边界位置相等时，该赋值语句并无实用）
            while (l < r&&arr[l].getDist() <= key)      //同理，左边界值不大于关键字且左边界位置没有越过右边界位置，保持左边界右移
            {
                l++;
            }arr[r] = arr[l];                   //同理，将右边界值用左边界值覆盖
        }                                       //整个循环结束后，左右边界应指向同一处
        arr[l] = temp;                             //将关键字覆盖到边界同时所指的位置，此时关键字左边的全部不比他大，右边的全部不比它小
        quickSort(arr, left, l - 1);              //递归
        quickSort(arr, l + 1, right);
    }
}