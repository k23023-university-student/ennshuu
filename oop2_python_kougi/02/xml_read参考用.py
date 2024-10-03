import xml.etree.ElementTree as ET
tree = ET.parse('lecture02_data.xml')
root = tree.getroot()
print(root.tag)
print(root.attrib)
print(root[0])
print(root[0].tag)
# article
print(root[0].attrib)
# {'title': '卒業論文'}
print(root[1][2].tag)
# chaper
print(root[1][2].attrib)
# {'id': '3', 'name': '仕事', 'pages': '6'}
