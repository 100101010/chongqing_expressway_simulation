//
// Created by 帆桥 on 2019/6/27.
//

#include "initData.hpp"
#include "Utils/Vector.hpp"
#include <fstream>

void generate(Util::Vector<int>& path) {
    std::fstream file;
    std::string filename = "F:\\ClionCode\\python_file\\generatePath.py";
    file.open(filename, std::ios::out);
    file<<"# coding=gbk\n";
    file<<"from graphviz import Graph\n"
          "\n"
          "A = Graph(\"G\", engine=\"sfdp\", format=\"jpg\")\n";
    for (int i = 0; i < path.size(); ++i) {
        file<<"A.node('"<<path[i]<<"', "<<"'"<<Nodes[path[i]-1]<<"', fontname='FangSong')\n";
    }
    for (int j = 0; j < path.size() - 1; ++j) {
        file<<"A.edge('"<<std::to_string(path[j])<<"', '"<<std::to_string(path[j+1])<<"', color='green')\n";
    }
    file<<"A.render(filename='abd', directory='F:/ClionCode/images', view=True)\n"; // 更改view查看图片
    file.close();
    system("C:\\Users\\HP\\AppData\\Local\\Programs\\Python\\Python35\\python.exe -u F:\\ClionCode\\python_file\\generatePath.py");
    system("move F:\\ClionCode\\images\\abd F:\\ClionCode\\dot_file");
}