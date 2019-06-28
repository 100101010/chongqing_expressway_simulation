//
// Created by 帆桥 on 2019/6/27.
//

// 二分查找
#include <string>
#include "Utils/Vector.hpp"
int binarySearch(Util::Vector<std::pair<std::string, int> > data, std::string name, int begin, int end) {
    while (end>=begin){
        int mid = begin + (end - begin)/2;
        if (data[mid].first == name)
            return data[mid].second;
        else if (data[mid].first > name)
            end = mid - 1;
        else
            begin = mid + 1;
    }
    return -1;
}