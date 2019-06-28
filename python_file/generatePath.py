# coding=gbk
from graphviz import Graph

A = Graph("G", engine="sfdp", format="jpg")
A.node('3', '荣昌', fontname='FangSong')
A.node('6', '永川', fontname='FangSong')
A.node('20', '白沙', fontname='FangSong')
A.edge('3', '6', color='green')
A.edge('6', '20', color='green')
A.render(filename='abd', directory='F:/ClionCode/images', view=True)
