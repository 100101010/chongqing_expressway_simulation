//
// Created by 帆桥 on 2019/6/28.
//

#include <cstring>
#include <iostream>
#include "initData.hpp"
#include "Utils/Vector.hpp"
#include "Utils/AVLTree.hpp"
#include "Utils/optimizeHelp.hpp"

const int INFF = 0x3c3c3c3c - 1;

extern bool visit[150];
extern long dist[150];
extern int minPath[150][150];

using pathType = Util::Vector<Util::Vector<int>>;
extern pathType Path;

void dijkstraByAVL(int start) {
    Path.clear();
    std::memset(minPath, -1, sizeof(minPath));
    std::memset(visit, false, sizeof(visit));
    visit[start] = true;
    for(int i = 1; i <= countNodes; i++){
        dist[i] = Edges[start][i];
        for(int j = 1; j <= countNodes; j++){
            minPath[i][j] = -1;
        }
        if(dist[i] < INFF){
            minPath[i][1] = start;
            minPath[i][2] = i;
        }
    }
    int k, minDist;
//    创建AVL树
    Utilt::distance* tem = new Utilt::distance[countNodes+2];
    for (int l = 1; l <= countNodes; ++l) {
        tem[l - 1].setDist(dist[l]);
        tem[l - 1].setIndex(l);
    }
    Util::AVLTree<Utilt::distance> distMinHeap;
    for (int m = 0; m < countNodes; ++m) {
        distMinHeap.insert(tem[m]);
    }

    for(int i = 1; i <= countNodes; i++){

        // 找出未访问的最小距离的结点(通过最小堆)
        minDist = distMinHeap.minimum().getDist();
        k = distMinHeap.minimum().getIndex();
        distMinHeap.remove(distMinHeap.minimum());

        if(minDist == INFF)
            break;
        // 标记k结点被访问
        visit[k] = true;
        // 更新结点
        for(int w = 1; w <= countNodes;w++){
            if(dist[w] > minDist + Edges[k][w]) {
                dist[w] = minDist + Edges[k][w]; // 松弛操作
                for(int j = 1; j <= countNodes; j++)
                    minPath[w][j] = -1;
                for(int j = 1; j <= countNodes; j++){
                    minPath[w][j] = minPath[k][j];
                    if(minPath[w][j]==-1){
                        minPath[w][j] = w;
                        break;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= countNodes; ++i) {
        Util::Vector<int> tempPath;
        for (int j = 1; j <= countNodes; ++j) {
            if (minPath[i][j] != -1)
                tempPath.push_back(minPath[i][j]);
        }
        Path.push_back(tempPath);
    }
    delete[] tem;
}