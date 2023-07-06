import glob
import os
import zipfile
import getpass

# 学籍番号を取得
# user名を取得
user = getpass.getuser()
s = list(user)
# 末尾2文字を削除
for i in range(2):
    s.pop()
# student_numberに代入
student_number = "".join(s)

# ディレクトリの中で最も大きな数のファイル名を取得
# pathにカレントディレクトリを代入
path = "./"
# path内のファイル名を取得
files_path = os.listdir(path)
# path内のディレクトリ名を取得
files_dir = [f for f in files_path if os.path.isdir(os.path.join(path, f))]
# path内のファイル名を取得
number = os.listdir(path)
# ファイル名を昇順にソート
number.sort()
# zip_make.pyを除外
number.remove("make_zip.py")
# 既存のzipファイル名を除外
if number[-2] == student_number + ".zip":
    number.remove(student_number + ".zip")
if number[-1] == student_number + "_issues.zip":
    number.remove(student_number + "_issues.zip")
# 最大のファイル名を取得
max_number = "".join(max(number))
# ファイル名が1桁の場合は0を付ける
if int(max_number) - 10 < 0:
    file_number = "0" + str(max_number)
else:
    file_number = str(max_number)


# .cファイル名を取得
def file_name(zip_file_name):
    # ファイル名を取得
    files = ""
    files = glob.glob(f"./{max_number}/*.c")
    # zip_file_nameが空の場合は昇順にソート
    if zip_file_name == "":
        files.sort()
    else:
        files.sort(reverse=True)
    return files


# issue,challengeの数を取得
# ファイル名を取得
files = file_name("")
# 学籍番号を大文字に変換
student_number_lower = student_number.capitalize()
counter = 0
# 5回繰り返す
for i in range(5):
    n = 0
    for n in range(5):
        if (
            files[-i]
            not in f"./{max_number}/{file_number}_issue{n}_{student_number_lower}.c"
        ):
            n += 1
        else:
            counter += 1
    for n in range(5):
        if (
            files[-i]
            not in f"./{max_number}/{file_number}_challenge{n}_{student_number_lower}.c"
        ):
            n += 1
        else:
            counter += 1
    i += 1
issue_number = counter

# zipファイルを作成
files = file_name("")
i = 0
while i <= int(issue_number):
    files.pop()
    i += 1
with zipfile.ZipFile(f"{student_number}.zip", "w") as zipF:
    for file in files:
        zipF.write(file, compress_type=zipfile.ZIP_DEFLATED)

# issueのzipファイルを作成
files = file_name("_issues")
i = 0
issue_number = len(files) - issue_number
while i < issue_number:
    files.pop()
    i += 1
with zipfile.ZipFile(f"{student_number}_issues.zip", "w") as zipF:
    for file in files:
        zipF.write(file, compress_type=zipfile.ZIP_DEFLATED)
