import xml.etree.ElementTree as ET



def lecture02_02() -> None:
    # implement me


    new_root = ET.Element('book')#bookルートツリーの作成
    new_article = ET.SubElement(new_root, 'article')#articleをbookの子要素として作成
    new_article.attrib = {'title': '卒業論文'}#articleの属性を設定
    new_chapter = ET.SubElement(new_article, 'chapter')#chapterをarticleの子要素として作成
    new_chapter.attrib = {'id': '1', 'name': 'はじめに', 'pages': '2'}#chapterの属性を設定
    new_chapter = ET.SubElement(new_article, 'chapter')#chapterをarticleの子要素として作成
    new_chapter.attrib = {'id': '2', 'name': '基礎理論', 'pages': '8'}#chapterの属性を設定
    new_chapter = ET.SubElement(new_article, 'chapter')
    new_chapter.attrib = {'id': '3', 'name': '実験方法', 'pages': '6'}
    new_chapter = ET.SubElement(new_article, 'chapter')
    new_chapter.attrib = {'id': '4', 'name': '結果と考察', 'pages': '2'}
    new_chapter = ET.SubElement(new_article, 'chapter')
    new_chapter.attrib = {'id': '5', 'name': 'まとめ', 'pages': '1'}
    new_chapter = ET.SubElement(new_article, 'chapter')
    new_chapter.attrib = {'id': '6', 'name': '参考文献', 'pages': '2'}
    new_novel = ET.SubElement(new_root, 'novel')
    new_chapter = ET.SubElement(new_novel, 'chapter')
    new_chapter.attrib = {'id': '1', 'name': '1日のはじまり', 'pages': '2'}
    new_chapter = ET.SubElement(new_novel, 'chapter')
    new_chapter.attrib = {'id': '2', 'name': '朝食', 'pages': '8'}
    new_chapter = ET.SubElement(new_novel, 'chapter')
    new_chapter.attrib = {'id': '3', 'name': '仕事', 'pages': '6'}
    new_chapter = ET.SubElement(new_novel, 'chapter')
    new_chapter.attrib = {'id': '4', 'name': '帰宅後', 'pages': '2'}
    new_chapter = ET.SubElement(new_novel, 'chapter')
    new_chapter.attrib = {'id': '5', 'name': '新しい朝', 'pages': '1'}
    

    print(ET.tostring(new_root, encoding='utf-8', xml_declaration=True))
    with open('lecture02_02_data.xml', 'wb') as f:
        import xml.dom.minidom as md
        f.write(md.parseString(ET.tostring(new_root, encoding='utf-8', xml_declaration=True)).toprettyxml(indent='  ',encoding="utf-8"))
    

if __name__ == '__main__':
    lecture02_02()
