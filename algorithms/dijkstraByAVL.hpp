//
// Created by 帆桥 on 2019/6/28.
//

#ifndef CLIONCODE_DIJKSTRABYAVL_HPP
#define CLIONCODE_DIJKSTRABYAVL_HPP

#include <cstring>
#include "Utils/Vector.hpp"

using pathType = Util::Vector<Util::Vector<int>>;
extern pathType Path;

extern void dijkstraByAVL(int start);
#endif //CLIONCODE_DIJKSTRABYAVL_HPP
