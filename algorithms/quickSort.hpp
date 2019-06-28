//
// Created by 帆桥 on 2019/6/25.
//

#ifndef CLIONCODE_QUICKSORT_HPP
#define CLIONCODE_QUICKSORT_HPP

#include "Utils/Vector.hpp"
#include "Utils/optimizeHelp.hpp"
using T = Util::Vector<std::pair<std::string, int>>;

extern void quicksortByPair(T &a, int left, int right);
extern void quickSort(Utilt::distance* arr,int left,int right);

#endif //CLIONCODE_QUICKSORT_HPP
