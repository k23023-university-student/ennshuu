#!/usr/bin/env python
# -*- coding: utf-8 -*-

def lecture01_02(t: tuple, a: list[int]) -> None:
    k = list(t) + a # kを作成
    k.append(1)# kの要素に１を加える
    print(k)# kを出力
    print(max(k));# kの最大値を出力
    print(min(k))# kの最小値を出力
    print(sum(k))# kの合計値を出力
    print(sorted(k))# kの昇順ソート結果を出力
    pass # passは何もしない関数の時に書くおまじない（実装時に消すこと）


# main関数に相当する以下は変更しないこと
if __name__ == '__main__':
    i=(1,5,8,2)
    j=[10,3,7,4]
    lecture01_02(i, j)
    print(f"関数呼び出し後のに期待されるi=(1,5,8,2)")
    print(f"実際のi={i}")
    print(f"関数呼び出し後に期待されるj=[10,3,7,4]")
    print(f"実際のj={j}")