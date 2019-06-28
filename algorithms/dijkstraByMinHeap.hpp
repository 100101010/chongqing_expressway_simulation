//
// Created by 帆桥 on 2019/6/28.
//

#ifndef CLIONCODE_DIJKSTRABYMINHEAP_HPP
#define CLIONCODE_DIJKSTRABYMINHEAP_HPP

#include <cstring>
#include "Utils/Vector.hpp"

using pathType = Util::Vector<Util::Vector<int>>;
extern pathType Path;

extern void dijkstraByMinHeap(int start);
#endif //CLIONCODE_DIJKSTRABYMINHEAP_HPP
