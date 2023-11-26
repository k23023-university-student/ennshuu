const weight = 300;
if(weight < 250){
    console.log('手数料200円')
}else if(weight < 500){
    console.log('手数料400円');
}else if(weight < 1000){
    console.log('手数料600円')
}else{
    console.log('取り扱いできません');
}