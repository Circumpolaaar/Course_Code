class Outer {
    public static Inter method() {
        //返回匿名inter类型，这个实例进行show()
        return new Inter(){
            public void show(){
                System.out.println("DuluDulu");
            }
        };
        
        
    }
}