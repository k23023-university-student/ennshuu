package jp.ac.ait.k23023;

import java.util.Random;
import java.util.Scanner;


public class SimpleRPG {

    // このクラスでは、画面からの入力をいろいろなメソッドで行うため、
    // フィールド化しておく
    final static Scanner scanner = new Scanner(System.in);

    Hero hero;
    Enemy enemy;

    /**
     * 主人公を生成して返すメソッド
     * @return 主人公オブジェクト
     */
    Hero createHero() {

        //主人公の名前を入力させます
        System.out.println("主人公の名前を入力");
        String name = scanner.nextLine();


        System.out.println("職業の種類を選択（1: 学生, 2: 社畜, 3: 自由人)");
        String jobSelection = scanner.nextLine();
        Hero hero;
        switch (jobSelection){
            case "1"://学生
                hero = new HeroStudent(name,
                        new Random().nextInt(41) + 80,  // HP   80 〜 120
                        new Random().nextInt(8) + 8,   // ATK   8 〜 15
                        new Random().nextInt(8) + 8,   // DEF   8 〜 15
                        new Random().nextInt(8) + 8);
                break;
            case "2"://社畜
                hero = new HeroWorker(name,
                        new Random().nextInt(41) + 80,  // HP   80 〜 120
                        new Random().nextInt(8) + 8,   // ATK   8 〜 15
                        new Random().nextInt(8) + 8,   // DEF   8 〜 15
                        new Random().nextInt(8) + 8);
                break;
            default://自由人
                hero = new HeroFreePerson(name,
                        new Random().nextInt(41) + 80,  // HP   80 〜 120
                        new Random().nextInt(8) + 8,   // ATK   8 〜 15
                        new Random().nextInt(8) + 8,   // DEF   8 〜 15
                        new Random().nextInt(8) + 8);
                break;
        }
        return hero;
    }

    /**
     * 敵を生成して返すメソッド
     * @return 敵オブジェクト
     */
    Enemy createEnemy() {

        final String[] ENEMY_NAMES = {"睡魔の種　大盛りご飯", "睡魔の種　寝不足", "睡魔の種　風邪薬", "睡魔の種　暖かい空気", "睡魔の種　話が無駄に長いおじいさん"};

        // 上記配列から、ランダムに1つだけの名前を抽出して敵の名前とする。
        String name = ENEMY_NAMES[new Random().nextInt(ENEMY_NAMES.length)];

        Enemy enemy = new Enemy( // パラメータ   ランダム範囲
                name,
                new Random().nextInt(151) + 50,  // HP      50 〜 200
                new Random().nextInt(11) + 10,  // ATK  10 〜 20
                new Random().nextInt(11) + 5,   // DEF  5 〜 15
                new Random().nextInt(11) + 10); // AGI  10 〜 20

        return enemy;

    }

    /**
     *  主人公の行動
     * @return falseの場合続行不能
     */
    boolean heroAction() {
        // 主人公の1回分の行動決定と行動を行わせるメソッド


        IHeroJob job = (IHeroJob)hero;
        // 画面より、攻撃か逃亡かを選択させ、その行動結果を画面に表示します
        System.out.println("主人公の行動を決めてください(1: 睡魔の種に立ち向かう, 2: 特殊行動(" + job.getSpecialAttackName() + "), それ以外: 何もせず素直に寝る)");
        String input = scanner.nextLine();

        if (input.equals("1")) {
            // 攻撃だった場合
            AttackResult ret = hero.attack(enemy);
            System.out.println(enemy.getName() + "の効力を" + ret.damage + "だけ減らした " + enemy.getName() + "の効力の残り" + enemy.getHp());
            if (ret.state == AttackResult.BATTLE_END) {
                // 戦闘終了
                System.out.println(enemy.getName() + "の効力を完全に無効化した。主人公の目は覚め、ゲームクリア");
                return false; // 続行不能
            }
            // 戻り値は、行動により戦闘続行可否をbooleanで返します
            return true;

        } else if(input.equals("2")){
            //特殊行動のとき
            System.out.println("特殊行動 " + job.getSpecialAttackName() + "を発動！");
            AttackResult ret = job.specialAttack(enemy);
            System.out.println(enemy.getName() + "の効力を" + ret.damage + "だけ減らした \n" + enemy.getName() + "の効力の残り" + enemy.getHp());
            if (ret.state == AttackResult.BATTLE_END) {
                // 戦闘終了
                System.out.println(enemy.getName() + "の効力を完全に無効化した。主人公の目は覚め、ゲームクリア");
                return false; // 続行不能
            }
            // 戻り値は、行動により戦闘続行可否をbooleanで返します
            return true;

        }else{
            // 逃亡だった場合
            System.out.println(hero.getName() + "は寝ました。ゲームオーバー");
            return false; // 続行不能
        }
    }

    /**
     *  敵の行動
     * @return falseの場合続行不能
     */
    boolean enemyAction() {
        // 敵の1回分の攻撃行動を行わせるメソッド（敵は攻撃の行動のみ行います）
        // 攻撃だった場合
        AttackResult ret = enemy.attack(hero);
        System.out.println(hero.getName() + "に" + ret.damage + "の眠気を与えた " + hero.getName() + "が眠るまで残り" + hero.getHp());

        if (ret.state == AttackResult.BATTLE_END) {
            // 戦闘終了
            System.out.println(hero.getName() + "は寝落ちてしまった。ゲームオーバー。");
            return false; // 続行不能
        }
        // 戻り値は、行動により戦闘続行可否をbooleanで返します
        return true;
    }

    /**
     *  行動のループ処理
     */
    void battleLoop() {
        //戦闘処理の無限ループを用意します
        while(true) {
            // 無限ループ内では、主人公と敵の素早さを比較し行動順序を入れ替え、それぞれの行動を行います
            // 行動により戦闘続行不可能になった場合は、その場で無限ループを抜け、メソッドを終了します
            if (hero.getAgi() >= enemy.getAgi()) {
                // 主人公のほうが早い
                if (!heroAction()) return;
                if (!enemyAction()) return;
            } else {
                if (!enemyAction()) return;
                if (!heroAction()) return;
            }
        }
    }

    public static void main(String[] args) {

        System.out.println("あなたは、今目の前にあるタスクをこなさなければならない。しかしながら、今にも寝落ちそうである。睡魔の種を確実に潰し、寝落ちることなく目覚めをキープせよ。");
        SimpleRPG app = new SimpleRPG();

        app.hero = app.createHero();


        String weaponName = "カフェイン飲料";
        //武器を装備
        app.hero.setWeapon(new Weapon(weaponName,5));
        System.out.println(weaponName + "を装備します");

        System.out.println(app.hero);
        app.enemy = app.createEnemy();
        System.out.println(app.enemy);

        app.battleLoop();
    }
}