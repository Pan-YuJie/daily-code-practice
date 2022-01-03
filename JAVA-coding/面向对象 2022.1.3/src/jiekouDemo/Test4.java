package jiekouDemo;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Submerge
 * Date: 2022-01-03
 * Time: 14:43
 */
class Animal{
    protected String name;

    Animal(String name){
        this.name=name;
    }

}

//不是所有的动物都会飞，一个个类可以实现多个接口，但不能继承多个类
interface IFlying{
    void fly();
}

interface IRuning{
    void run();
}

interface ISwimming{
    void swimming();
}

class Robbt extends Animal implements IRuning{
    Robbt(String name){
        super(name);
    }

    public void run(){
        System.out.println("Robbt正在跑");
    }
}

class Duck extends Animal implements IFlying,IRuning,ISwimming{
    public Duck(String name) {
        super(name);
    }

    @Override
    public void swimming() {
        System.out.println(name + "正在游泳");
    }

    public void fly(){
        System.out.println(this.name + "正在飞");
    }

    public void run(){
        System.out.println(name + "正在跑");
    }

}

class Frog extends Animal implements IFlying,IRuning,ISwimming{
    public Frog(String name) {
        super(name);
    }

    @Override
    public void swimming() {
        System.out.println(name + "正在蛙泳");
    }

    public void fly(){
        System.out.println(this.name + "正在飞");
    }

    public void run(){
        System.out.println(name + "正在跳");
    }

}

public class Test4 {

    public static void run(IRuning iRuning){
        iRuning.run();
    }

    public static void Swimming(ISwimming iSwimming){
        iSwimming.swimming();
    }

    public static void main(String[] args) {
        run(new Frog("haha"));
        run(new Duck("he11he"));
        Swimming(new Duck("Duck"));
        Robbt robbt=new Robbt("rrr");
        run(robbt);


    }

}


