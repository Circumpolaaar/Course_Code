/**
 * @Description:
 * @author liuxxxxx
 * @date 2024/8/12 20:01
 */

/**
 * @author: coke_and_ice
 * TODO  
 * 2024/8/12 20:01
 */
public class Teacher extends Worker{
    int my_salary=100;
    public void teach(){
        System.out.println(getAge()+" "+getName()+" is teaching.");
    }
    @Override
    // 2
    public Teacher work(){
        //问题3：work方法在Worker类中被定义，
                //而People类是其超类，
                //在其子类Teacher中不能返回People类
        System.out.println(getAge()+" "+getName()+" is working.");
        return new Teacher();
    }
    @Override
    // 3
    public int salary(){
        //问题4：超类Worker中的salary()方法
                //返回int类型，需保持一致
        return my_salary;
    }
}
