public class Person {
    String name;
    int age;
    String sex;

    //构造方法
    public Person(String name,int age,String sex) {
        this.name = name;
        
        this.sex = sex;
    }

    //setAge()
    public void setAge(int age){
        if(0<=age && age<=130){
            this.age = age;
        }
        else{
            System.out.println("invalid age");
        }
    }

    //getAge()
    public int getAge(){
        return this.age;
    }

    //work()
    public void work(){
        System.out.println(this.name +" is working!");
    }

    //showAge()
    public void showAge(){
        System.out.println(this.name +" is "+this.getAge()+" years old!");
    }

}