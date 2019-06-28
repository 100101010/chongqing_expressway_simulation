//
// Created by 帆桥 on 2019/6/27.
//

#include <cstring>
#include <iostream>
#include "initData.hpp"
#include "Utils/Vector.hpp"

const int INFF = 0x3c3c3c3c - 1;

bool visit[150];
long dist[150];
int minPath[150][150];

using pathType = Util::Vector<Util::Vector<int>>;
pathType Path;

void dijkstra(int start) {
//    std::cout<<start<<std::endl;
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
    for(int i = 1; i <= countNodes; i++){
        minDist = INFF;  // 初始化最小距离为特别大
        // 找出未访问的最小距离的结点
        for(int j = 1; j <= countNodes; j++){
            // 如果j结点没有访问，且start到j可达，到达距离小于minDist
            if(!visit[j] && dist[j] < minDist){
                minDist = dist[j];
                k = j;
            }
        }
        if(minDist == INFF)
            break;
        // 标记k结点被访问
        visit[k] = true;
        // 更新结点
        for(int w = 1; w <= countNodes;w++){
            if(dist[w] > minDist + Edges[k][w]) {
                dist[w] = minDist + Edges[k][w]; // 松弛操作
                // 更改最短路径
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
}