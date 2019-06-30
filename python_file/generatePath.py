# coding=gbk
from graphviz import Graph

A = Graph("G", engine="sfdp", format="jpg")
A.node('8', '青杠', fontname='FangSong')
A.node('22', '江津', fontname='FangSong')
A.edge('8', '22', color='green')
A.render(filename='abd', directory='F:/ClionCode/images', view=True)
