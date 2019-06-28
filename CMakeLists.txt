cmake_minimum_required(VERSION 3.13)
project(ClionCode)

set(CMAKE_CXX_STANDARD 11)
#add_compile_options(-fexec-charset=GBK)

set(CMAKE_INCLUDE_CURRENT_DIR  ON)
set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH C:\\Qt\\Qt5.7.1\\5.7\\mingw53_32) #这里需要填入自己安装的路径

find_package(Qt5Widgets)
find_package(Qt5Core)
find_package(Qt5Gui)
find_package(Qt5Xml)

set(UI_FILES)

set(RC_FILES)

set(QRC_FILES)

set(SOURCE_FILES main.cpp mainwindow.cpp mainwindow.h CountSelect.cpp CountSelect.h Utils/Vector.hpp initData.cpp algorithms/quickSort.hpp Utils/MinHeap.hpp Utils/AVLTree.hpp algorithms/dijkstra.hpp randomSelect.h randomSelect.cpp initData.hpp Utils/otherUsefulUtility.cpp Utils/otherUsefulUtility.hpp algorithms/binarySearch.hpp algorithms/binarySearch.cpp algorithms/dijkstra.cpp algorithms/quickSort.cpp Utils/drawImagePy.hpp Utils/drawImagePy.cpp algorithms/dijkstraByAVL.hpp algorithms/dijkstraByAVL.cpp algorithms/dijkstraByMinHeap.hpp algorithms/dijkstraByMinHeap.cpp Utils/optimizeHelp.hpp algorithms/dijkstraByQuickSort.hpp algorithms/dijkstraByQuickSort.cpp)

add_executable(ClionCode ${SOURCE_FILES})

target_link_libraries(ClionCode Qt5::Widgets Qt5::Xml)

qt5_use_modules(ClionCode Core Widgets Gui)

#C:\Qt\Qt5.7.1\5.7\mingw53_32\bin\uic.exe F:\ClionCode\CountSelect.ui -o F:\ClionCode\cmake-bui
#ld-debug\ClionCode_autogen\include\ui_CountSelect.h
