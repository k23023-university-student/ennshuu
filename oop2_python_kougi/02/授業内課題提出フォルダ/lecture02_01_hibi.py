#!/usr/bin/env python
# -*- coding: utf-8 -*-
import csv

def lecture02_01_printHeroStatus() -> None:
    # implement me
    hero_header = []
    hero_data = []
    with open('lecture02_Hero.csv') as f:
        reader = csv.reader(f)
        for row in reader:
            if len(hero_header) == 0:
                hero_header = row
            else :
                if(len(hero_data) == 0):
                    hero_data.append(row)

    print(hero_header)
    print(hero_data)

#def lecture02_01_printWeaponStatus() -> None:
    # implement me

"""def lecture02_01_printHeroStatusWithWeapon() -> None:
    # implement me
    # ステータス情報を出力する
    print(f"{weapon_name}を装備した{hero_name}のステータスは" +
        f"HP:{hero_hp+weapon_hp}," +
        f"MP:{hero_mp+weapon_mp}," +
        f"Atk:{hero_atk+weapon_atk}," +
        f"Def:{hero_def+weapon_def}," +
        f"Age:{hero_age+weapon_age}")"""

if __name__ == '__main__':
    lecture02_01_printHeroStatus()
    #lecture02_01_printWeaponStatus()
    #lecture02_01_printHeroStatusWithWeapon()