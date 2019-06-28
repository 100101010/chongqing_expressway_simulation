//
// Created by 帆桥 on 2019/6/26.
//

#ifndef CLIONCODE_INITDATA_HPP
#define CLIONCODE_INITDATA_HPP

#include <string>
#include "Utils/Vector.hpp"
extern const int INF;
extern Util::Vector<std::pair<std::string, int> > nodesMap; // 存储结点与编号的映射数据
extern Util::Vector<std::string> Nodes;// 存储全部结点
extern Util::Vector<int> rescueNodes;// 存储救援结点
extern int Edges[50][50];
extern int countNodes;

extern void init();

#endif //CLIONCODE_INITDATA_HPP
