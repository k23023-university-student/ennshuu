#!/usr/bin/env python
# -*- coding: utf-8 -*-

def lecture01_01() -> None:
    h={}
    h["ID"] = 'k23023'
    # implement me
    print('hの内容: ')
    h["attributes"] = ('岡田隆之介',19,'男')

    # 表示
    print(h)
    print('キー一覧: ')
    for x in h.keys():
        print(x)
    print('h.keys()で取得したオブジェクトの型: ')
    print(type(h.keys()))

    print('h[“attributes”]の型: ')
    print(type(h["attributes"]))

    print('h[“attributes”]の各要素: ')

    for e in h["attributes"]:
        print(e)

    print('h[“attributes”]の各要素の型: ')

    for e in h["attributes"]:
        print(type(e))
    
if __name__ == '__main__':
    lecture01_01()