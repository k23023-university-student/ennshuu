package jp.ac.ait.k23023;

import java.util.Random;

public class CharacterBase {
    private String name; // - 名前
    private int hp; // - 体力
    private int atk; // - 攻撃力
    private int def; // - 防御力
    private int agi; // - 素早さ
    /**
     * 各ステータスを指定して初期化
     * @param name
     * @param hp
     * @param atk
     * @param def
     * @param agi
     */
    public CharacterBase(String name, int hp, int atk, int def, int agi){
        // それぞれ引数の値で初期値セット
        this.name = name;
        this.hp = hp;
        this.atk = atk;
        this.def = def;
        this.agi = agi;
    }



    public String getName() {
        return name;
    }

    public int getHp() {
        return hp;
    }

    public int getAtk() {
        return atk;
    }

    public int getDef() {
        return def;
    }

    public int getAgi() {
        return agi;
    }


    public AttackResult attack(CharacterBase target){
        Random r = new Random();

        // 敵に対して攻撃を行う処理を実装します。

        // 引数の攻撃対象targetに対して与えることのできるダメージを算出
        // 与えるダメージ = (自身の攻撃力 - 敵の防御力 / 2)(小数点以下切り上げ) に、-3〜+3のランダムな値を加算
        int damage = (int)Math.ceil((double)this.getAtk() - (target.getDef() / 2.0))
                + (r.nextInt(7) - 3); // ← −3〜+3のランダムな値

        // 与えるダメージの計算式に従って計算されたダメージ量を引数の相手に与えます。
        boolean isBattleEnd = target.receiveDamage(damage);

        // 戻り値は、AttackResultのインスタンスを生成し、ダメージ量と戦闘続行かどうかの状態をAttackResultの定数フィールドを使って設定して返します。
        AttackResult ret = new AttackResult();
        ret.damage = damage;
        if (isBattleEnd) {  // 戦闘が終わる場合により詳細な状態を渡したい
            ret.state = AttackResult.BATTLE_END;
        } // CONTINUE は初期値なので、ENDの場合のみ設定すればOK
        return ret;
    }

    /**
     * ダメージを受ける
     * @param damage 受けるダメージ量
     * @return 戦闘続行可能な場合 false , 不可能な場合 true
     */
    public boolean receiveDamage(int damage) {
        // 勇者がダメージを受ける。(自分で呼び出さず、敵であるEnemyから呼ばれる)

        // フィールドのhpから引数のダメージ分を減算し、
        this.hp -= damage;

        // 0を下回る場合はhpに0を代入する。
        if (this.hp <= 0) {
            this.hp = 0;
            // 戻り値はダメージを受けたあとのHPが0以下の場合trueを返し、戦闘続行不可能とする。
            return true;
        }
        // HPはまだ残っているので、戦闘は続行
        return false;
    }

    @Override
    public String toString() {
        return String.format("%s : 体力 %d, 攻撃力 %d, 防御力 %d, 素早さ %d", this.name, this.hp, this.atk, this.def, this.agi);
    }
}
