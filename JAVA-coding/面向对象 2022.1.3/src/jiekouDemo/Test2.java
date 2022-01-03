package jiekouDemo;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Submerge
 * Date: 2022-01-03
 * Time: 14:18
 */

interface IA{
    int A=10;//接口种变量要初始化 默认public static final  --》常量 需要初始化

    void func();//默认public abstract

}

interface IB{
    void funcB();
}

abstract class BClass{

}

class AClass extends BClass implements IA,IB{  //一个类可以implements实现多个接口, 可以通过extends继承 一个 普通类或抽象类

    @Override
    public void funcB() {

    }

    @Override
    public void func() {
        System.out.println("AClass");
        System.out.println(A);
    }
}


public class Test2 {

}
