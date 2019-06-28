//
// Created by 帆桥 on 2019/6/25.
//

#ifndef CLIONCODE_DIJKSTRA_HPP
#define CLIONCODE_DIJKSTRA_HPP

#include <cstring>
#include "Utils/Vector.hpp"

extern bool visit[150];
extern long dist[150];
extern int minPath[150][150];

using pathType = Util::Vector<Util::Vector<int>>;
extern pathType Path;

extern void dijkstra(int start);
#endif //CLIONCODE_DIJKSTRA_HPP
