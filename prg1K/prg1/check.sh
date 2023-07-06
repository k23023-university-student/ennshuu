
for i in $(ls *.c| xargs echo)
do
   gcc $i
   if [ $? == 0 ]; then
   echo "$i:問題なし"
   else
   echo "$i:エラー発生"
   fi
done
rm a.out
