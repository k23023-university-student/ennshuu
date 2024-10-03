#!/usr/bin/env python
# -*- coding: utf-8 -*-
import csv

def lecture02_01_printHeroStatus() -> None:
    # implement me
    print("IDが1のヒーローの名前とステータスは")
    hero_header = [] #ヘッダーを格納する変数

    with open('lecture02_Hero.csv') as file:
        reader = csv.reader(file)
        for row in reader:

            if len(hero_header) == 0:# ヘッダーが空の場合
                hero_header = row # ヘッダーを格納

            else:
                if(row[0] == '1'): # IDが1のヒーローのステイタスを出力
                    
                    print(f"名前:{row[1]}," +
                          f"HP:{row[2]}," +
                          f"MP:{row[3]}," +
                          f"Atk:{row[4]}," +
                          f"Def:{row[5]}," +
                          f"Age:{row[6]}")

def lecture02_01_printWeaponStatus() -> None:
    # implement me
    print("IDが1の武器の名前とステータスは")
    weapon_header = []
    with open('lecture02_Weapon.csv') as file:
        reader = csv.reader(file)
        for row in reader:

            if len(weapon_header) == 0:
                weapon_header = row
            else:
                if(row[0] == '1'): # IDが1の武器のステイタスを出力
                    print(f"名前:{row[1]}," +
                          f"HP:{row[2]}," +
                          f"MP:{row[3]}," +
                          f"Atk:{row[4]}," +
                          f"Def:{row[5]}," +
                          f"Age:{row[6]}")
                
def lecture02_01_printHeroStatusWithWeapon() -> None:
    # implement me
    # ステータス情報を出力する
    # print(f"{weapon_name}を装備した{hero_name}のステータスは" +
    #     f"HP:{hero_hp+weapon_hp}," +
    #     f"MP:{hero_mp+weapon_mp}," +
    #     f"Atk:{hero_atk+weapon_atk}," +
    #     f"Def:{hero_def+weapon_def}," +
    #     f"Age:{hero_age+weapon_age}")
    pass

if __name__ == '__main__':
    lecture02_01_printHeroStatus()
    lecture02_01_printWeaponStatus()
    lecture02_01_printHeroStatusWithWeapon()