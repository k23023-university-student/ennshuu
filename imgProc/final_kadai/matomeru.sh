
#!/bin/bash

# コピー先のディレクトリ
destination="copiedFiles"

# コピー先ディレクトリが存在しない場合は作成する
if [ ! -d "$destination" ]; then
    mkdir "$destination"
fi

# サブディレクトリ内を探索
for file in $(find . -type f -name "issue*_k23023.cpp" -o -name "issue*_result_k23023.png"); do
    cp "$file" "$destination"
done

echo "ファイルのコピーが完了しました。"
