package jp.ac.ait.k23023;
import java.awt.desktop.SystemEventListener;
import java.util.Random;
public class Hero extends CharacterBase{


    private Weapon weapon = null;//武器の装備状態

    public Hero(String name, int hp, int atk, int def, int agi) {
        //スーパークラスの値をセット
        super(name, hp, atk, def, agi);
    }

    /**
     * CharacterBaseとは違う処理を実装する攻撃処理
     * @param target 攻撃対象
     * @return 攻撃結果
     */
    @Override
    public AttackResult attack(CharacterBase target) {

        // ランダムな数値の生成に使用する乱数生成器を初期化
        Random r = new Random();

        // 引数の攻撃対象に対して与えることのできるダメージを算出
        // 与えるダメージ = (自身の攻撃力 - 敵の防御力 / 2)(小数点以下切り上げ) に、-3〜+3のランダムな値を加算
        int damage = (int)Math.ceil((double)this.getAtk() - (target.getDef() / 2.0))
                + (r.nextInt(7) - 3); // ← −3〜+3のランダムな値

        // 素早さの比較値を取得
        int agiDiff = this.getAgi() - target.getAgi();
        // 攻撃成功率 (初期値を100％としておく)
        double successRate = 1.0;

        if (agiDiff < 0) {
            // 遅い場合
            if (Math.abs(agiDiff) >= 5) {
                successRate = 0.6;   // 差が5以上: 60%
            } else {
                successRate = 0.7;   // 差が5未満: 70%
            }
        } else if (agiDiff == 0) {
            // 等速
            successRate = 0.8;   // 同じ場合: 80%
        } else {
            // 速い
            if (Math.abs(agiDiff) < 3) {
                successRate = 0.9;   // 差が3未満: 90%
            }
        }

        // 上記成功判定で攻撃が成功する(それ以外は失敗)
        // Random#nextDoubleは、1.0以下のランダムな浮動小数点の値を生成する
        if (r.nextDouble() >= successRate) {
            // 失敗判定
            System.out.println("睡魔の種の効力を全く減らせなかった...");
            AttackResult ret = new AttackResult();
            ret.damage = 0;   // ダメージ処理をしないで0を返す
            return ret;
        }

        // 攻撃成功時 15% の確率でクリティカル
        if (r.nextDouble() < 0.15) {
            System.out.println("素晴らしい攻撃！睡魔の種の無力化にかなり大きく作用した！");
            damage *= 2;
        }

        // 引数の攻撃対象がダメージを受ける
        boolean isBattleEnd = target.receiveDamage(damage);
        AttackResult ret = new AttackResult();
        // 攻撃を行ったことによる行動結果を生成して返す
        ret.damage = damage;
        if (isBattleEnd) {
            // 戦闘終了の条件を満たす場合、勇者の勝利となる
            ret.state = AttackResult.BATTLE_END;
        }
        return ret;
    }


    @Override

    public int getAtk(){
        return this.weapon != null ? super.getAtk() + this.weapon.getAtk() : super.getAtk();
    }

    public Weapon getWeapon() {
        return weapon;
    }

    public void setWeapon(Weapon weapon) {
        this.weapon = weapon;
    }
}
