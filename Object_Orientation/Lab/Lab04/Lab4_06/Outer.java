class Outer {
    public int num = 10;

    class Inner {
        public int num = 20;

        public void show() {
            //局部变量，直接访问
            int num = 30;
            System.out.println(num);
            
            //当前对象(this)是inner
            System.out.println(this.num);
            
            //外部类.this指的是外部类的对象
            System.out.println(Outer.this.num);
        }
    }
}
