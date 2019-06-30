//
// Created by 帆桥 on 2019/6/25.
//
#include <fstream>
#include <string>
#include "Utils/Vector.hpp"
#include "algorithms/quickSort.hpp"
#include <cstring>
#include <iostream>
#include <windows.h>

const int INF = 0x3c3c3c3c - 1;
Util::Vector<std::pair<std::string, int> > nodesMap; // 存储结点与编号的映射数据
Util::Vector<std::string> Nodes;// 存储全部结点
Util::Vector<int> rescueNodes;// 存储后期救援结点
Util::Vector<int> preRescueNodes; // 存储前期救援结点
int Edges[50][50];
int countNodes;

// 读取结点数据
static void readNodesData() {
    std::fstream file;
    file.open("F:\\ClionCode\\data\\nodes.txt");
    int number;
    std::string nodeName;
    while (file.peek()!=EOF) {
        file >> number >> nodeName;
        auto tempPair = std::make_pair(nodeName, number);
        nodesMap.push_back(tempPair);
        Nodes.push_back(nodeName);
    }
    nodesMap.pop_back();
    Nodes.pop_back();
    file.close();
    countNodes = number;
}

// 读取边的数据
static void readEdgesData() {
    std::fstream file;
    file.open("F:\\ClionCode\\data\\edges.txt");
    int begin, end, value;
    std::memset(Edges, INF, sizeof(Edges)); // 将领接矩阵每个值设为INF，表示不可达
    for(int i = 0; i < 50; i++){
        Edges[i][i] = 0;
    }
    while (file.peek()!=EOF) {
        file >> begin >> end >> value;
        Edges[begin][end] = value;
        Edges[end][begin] = value;
    }
    file.close();
}

// 读取救援结点
static void readRescueNodesData() {
    std::fstream file;
//    读取后期救援结点
    file.open("F:\\ClionCode\\data\\rescueNodes.txt");
    int number;
    while (file.peek()!=EOF) {
        file >> number;
        rescueNodes.push_back(number);
    }
    file.close();

//    读取前期救援结点
    file.open("F:\\ClionCode\\data\\preRescueNodes.txt");
    while (file.peek()!=EOF) {
        file >> number;
        preRescueNodes.push_back(number);
    }
    file.close();
}

bool judge(int n);
bool judgePre(int n);

static void genratePng() {
    std::fstream file;
    std::string filename = "F:\\ClionCode\\python_file\\generateGraph.py";
    file.open(filename, std::ios::out);
    file<<"# coding=gbk\n";
    file<<"from graphviz import Graph\n"
          "\n"
          "A = Graph(\"G\", engine=\"sfdp\", format=\"jpg\")\n";

//    读取结点(区分救援与普通结点)
    for (int i = 0; i < nodesMap.size(); ++i) {
        file<<"A.node('"<<i+1<<"', "<<"'"<<nodesMap[i].first;
        if (judge(i+1) && !judgePre(i+1)) // 如果是后期救援结点
            file<<"',color='green', fontname='FangSong')\n";
        else if (!judge(i+1) && judgePre(i+1)) // 如果是前期救援结点
            file<<"',color='blue', fontname='FangSong')\n";
        else
            file<<"', fontname='FangSong')\n";

    }

    for (int k = 1; k <= countNodes; ++k) {
        for (int m = k+1; m <= countNodes; ++m) {
            if (Edges[k][m]<101)
                file<<"A.edge('"<<std::to_string(k)<<"', '"<<std::to_string(m)<<"')\n";
        }
    }
    file<<"A.render(filename='abc', directory='F:/ClionCode/images', view=False)\n";
    file.close();
}

bool judgePre(int n) {
    for (int i = 0; i < preRescueNodes.size(); ++i) {
        if (n == preRescueNodes[i])
            return true;
    }
    return false;
}

bool judge(int n) {
    for (int i = 0; i < rescueNodes.size(); ++i) {
        if (n == rescueNodes[i])
            return true;
    }
    return false;
}

void init() {
    readNodesData();
    readEdgesData();
    readRescueNodesData();
    genratePng();

    // 通过python画图,生成路线图
    system("python -u F:\\ClionCode\\python_file\\generateGraph.py");
//    system("dot -Tjpg F:\\ClionCode\\dot_file\\temp.dot -o F:\\ClionCode\\images\\abc.jpg");
    system("move F:\\ClionCode\\images\\abc F:\\ClionCode\\dot_file");
//    对nodes的string进行排序,方便以后查找
    quicksortByPair(nodesMap, 0, countNodes-1);
}