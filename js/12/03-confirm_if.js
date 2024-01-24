const result = confirm('本当に削除してよいですか？');
if(result){
    console.log('削除しました');
}else{
    console.log('キャンセルしました')
}
console.log('ユーザが回答するまで実行されない')