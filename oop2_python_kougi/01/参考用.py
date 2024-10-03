# プログラム3
h = {} # hに空の辞書型オブジェクトを代入
h['ID'] = 'k19999kk'# 辞書型に値を保存するには配列のインデクスの代わりにキーを指定する
h['name'] = '勇者'
h['HP'] = 100
h['MP'] = 100
h['Atc'] = 0
h['Def'] = 10
h['Age'] = 42
h['武器'] = {'名前': '棍棒', 'HP補正': 10, 'MP補正': 0, 'Act補正': 20, 'Def補正': 0, 'Age補正': -3}
print(h)
print(h['ID']) # 辞書型の値にアクセスする時はキーを指定する
print(h['HP'])
print(h['武器'])
print(h.keys()) # キーがわからない時はkeys()メソッドでキー一覧を取得できる
if('武器' in h.keys()):
    print(h['武器'].keys()) # 武器のキーが存在する場合実行される

# ↑インタープリタで実行する時は空行でエンターキーを入力するとブロックを実行してくれる

for x in h.keys():
    print(x) # キー一覧を出力

# ↑インタープリタで実行する時は空行でエンターキーを入力するとブロックを実行してくれる

print(type(h))
# <class 'dict'>

# 3.9で追加された文法
# |演算子は辞書型同士をマージ（足し算）する
marged = {'dog': 'わん', 'caw': 'xxxx'} | {'cat': 'にゃー', 'caw': 'モー'}
print(marged)
# {'dog': 'わん', 'caw': 'モー', 'cat': 'にゃー'}

# |=演算子は配列やタプルの前方をキー，次を値として辞書型にマージできる
marged |= [('dog', 'bowwow'),('cat', 'meow')]
print(marged)
# {'dog': 'bowwow', 'caw': 'モー', 'cat': 'meow'}

# おまけ
# 辞書型からタプルのリストへ1
marged.items()
#dict_items([('dog', 'bowwow'), ('caw', 'モー'), ('cat', 'meow')])

# 辞書型からタプルのリストへ2
zip(marged.keys(), marged.values())
# <zip object at 0x10dba2f80>
print(list(zip(marged.keys(), marged.values())))
# [('dog', 'bowwow'), ('caw', 'モー'), ('cat', 'meow')]