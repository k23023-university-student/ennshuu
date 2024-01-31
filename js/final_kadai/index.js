//      // Import the functions you need from the SDKs you need
//      import { initializeApp, deleteApp } from "https://www.gstatic.com/firebasejs/10.7.2/firebase-app.js";
//      import { getDatabase, ref, set, remove, onValue, query } from "https://www.gstatic.com/firebasejs/10.7.2/firebase-database.js"
//      // TODO: Add SDKs for Firebase products that you want to use
//      // https://firebase.google.com/docs/web/setup#available-libraries
   
//      // Your web app's Firebase configuration
//      const firebaseConfig = {
//        apiKey: "AIzaSyDddQ43RvrUFhhmmIocDQe2qiLcHyXOEeQ",
//        authDomain: "ws-server-3f08d.firebaseapp.com",
//        databaseURL: "https://ws-server-3f08d-default-rtdb.firebaseio.com",
//        projectId: "ws-server-3f08d",
//        storageBucket: "ws-server-3f08d.appspot.com",
//        messagingSenderId: "1019760919499",
//        appId: "1:1019760919499:web:0ec7e98067e9abe5796c4e"
//      };
   
//      // Initialize Firebase
//      const app = initializeApp(firebaseConfig);
//      const db = getDatabase(app);
//      let ref1 = ref(db,'test/test1');
//      set(ref1, {
//      "temperature": 26,
//      "humidity": 43
//      });
//      const disconnect = onValue(ref1, function(snapshot) {
//      alert("value Changed!!!");
//      console.log(snapshot.val());
//  }, 
//  function(errorObject) {
//      alert("failed: " + errorObject.code);
//  } );
let btnElement; 
let wordList;
let mode = -1;
window.onload = () => {
    btnElement = document.querySelector("#start");
    btnElement.value = "単語リストを読み込み中、お待ちください";
    btnElement.disabled = true;
    //一人で
    document.settings.set_radio[0].addEventListener('change',()=>{
        mode = 0;
    });
    //オンライン対戦
    document.settings.set_radio[1].addEventListener('change',()=>{
        mode = 1;
    });
    //単語リストの取得
    fetch("./words.json").then((data)=>data.json()).then(
        (result)=>{
            wordList = result;
            btnElement.value = "ゲームを開始する"
            btnElement.disabled = false;
        }
        ).catch(()=>{
            btnElement.value = "単語リスト取得エラーです。開始できません"
        });
        btnElement.addEventListener('click',initGame)
};
let initGame = async ()=>{
    if(mode == 0){
        //ゲームのメイン画面を準備するコードをここに追加
    }else if(mode == 1){

    }else{
        alert("ゲームの進行方法を選択してください");
        return;
    }
    showCountdown();
    await countdown(5000);
    hideCountdown();

}
let countdown = async (ms)=>{
    //カウンドダウン
    for(let i=0;i<ms/1000;i++){
        document.querySelector(".countdown").textContent = (ms/1000)-i;
        await new Promise((resolve)=>{setTimeout(resolve,1000)});
    }
}
let showCountdown = () =>{
    document.querySelector(".option-area").style.visibility = "hidden";
    document.querySelector(".countdown").style.visibility = "visible";
}
let hideCountdown = () =>{
    document.querySelector(".option-area").style.visibility = "visible";
    document.querySelector(".countdown").style.visibility = "hidden";
}
let mainLoop = () =>{
    //ゲームのメインループ
    //配列から単語をランダムで選び、文字の並び順をシャッフルする機能をここに書く。
    //選ぶ単語の数だけ繰り返す
    //間違えたらその地点で終了とする
}
let checkAnswer = ()=>{

}