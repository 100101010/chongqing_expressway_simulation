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
extern Util::Vector<int> rescueNodes;// 存储后期救援结点
extern int Edges[50][50];
extern int countNodes;
extern Util::Vector<int> preRescueNodes;// 存储前期救援结点

extern void init();
extern bool judge(int n);
extern bool judgePre(int n);
#endif //CLIONCODE_INITDATA_HPP
