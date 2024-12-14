class Buyer {
    private String name;
    public Buyer(String name) {
        this.name = name;
    }

    public void buy(String sth) {
        System.out.println(name + "买了" + sth);
    }
}

class Chef {
    private String name;
    public Chef(String name) {
        this.name = name;
    }

    public void cook(String sth) {
        System.out.println(name + "做了" + sth);
    }
}


public class test {
    public static void main(String[] args) {
        // 创建
        Buyer gugu = new Buyer("姑姑");
        Buyer mum = new Buyer("妈妈");
        Buyer me = new Buyer("我");

        Chef dad = new Chef("爸爸");
        Chef shenshen = new Chef("婶婶");

        // 买
        gugu.buy("蔬菜");
        mum.buy("水果");
        me.buy("肉类");

        // 做
        dad.cook("菜");
        shenshen.cook("主食");
    }
}
