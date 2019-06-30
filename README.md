# 项目文件目录

- UI_file：存储Qt Designer生成的UI文件

  - CountSelect.ui：指定结点和预警级别选择窗口
  - randomSelect.ui：随机结点和预警级别显示窗口
  - mainwindow.ui：主窗口

- Utils：存储各种工具文件

  - AVLTree.hpp：AVL树实现
  - MinHeap.hpp：最小堆实现
  - Vector.hpp：STL中vector实现
  - drawImagePy.cpp/.hpp：生成可以绘制最短路径图片的Python文件
  - optimizeHelp.hpp：协助algorithms内dijkstra算法实现
  - otherUsefulUtility.cpp/.hpp：包含一些工具（编码转换，字符分割）

- algorithms：存储各种算法文件

  - binarySearch.cpp/.hpp：二叉搜索函数实现
  - dijkstra.cpp/.hpp：不带任何优化的dijkstra算法实现(带最短路径和最短路径值)
  - dijkstraByAVL.cpp/.hpp：带AVL树优化的dijkstra算法实现
  - dijkstraByMinHeap.cpp/.hpp：带最小堆优化的dijkstra算法实现
  - dijkstraByQuickSort.cpp/.hpp：带快排优化的dijkstra算法实现
  - quickSort.cpp/.hpp：快排实现

- data：存储结点与边的数据

  - edges.txt：存储边与权重的数据
  - nodes.txt：存储结点编号与名称的数据
  - rescueNodes.txt：存储救援结点编号和名称

- dot_file：存储graphviz画图时生成的中间文件

- images：存储画图过程中生成的图片

- python_file：存储画图的python文件

  - generateGraph.py：生成地图的python文件
  - generatePath.py：生成路径图片的python文件

  CountSelect.cpp/.hpp：指定结点和预警级别选择窗口的代码实现

  initData.cpp/.hpp：项目初始化数据（包括读取数据，生成可视化窗口和图片）

  mainwindow.cpp/.hpp：主窗口代码实现

  randomSelect.cpp/.hpp：随机结点和预警级别显示窗口的代码实现

对于预警级别，一级需要后期救援，二级需要前期救援
