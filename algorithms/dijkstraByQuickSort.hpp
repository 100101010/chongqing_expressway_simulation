//
// Created by 帆桥 on 2019/6/28.
//

#ifndef CLIONCODE_DIJKSTRABYQUICKSORT_HPP
#define CLIONCODE_DIJKSTRABYQUICKSORT_HPP

#include <cstring>
#include "Utils/Vector.hpp"

using pathType = Util::Vector<Util::Vector<int>>;
extern pathType Path;

extern void dijkstraByQuickSort(int start);
#endif //CLIONCODE_DIJKSTRABYQUICKSORT_HPP
