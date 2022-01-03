package jiekouDemo;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Submerge
 * Date: 2022-01-03
 * Time: 14:37
 */

interface IA1{
    void funcA();
}

//接口可以通过extends来拓展另一个接口
interface IB1 extends IA1{ //接口和接口之间使用extends来操作他们之间的关系 意为：拓展
    void funcB();
}

//当一个类通过implements实现拓展的接口，需要重写两个接口中的抽象方法
class C implements IB1{
    @Override
    public void funcB() {

    }

    @Override
    public void funcA(){

    }
}

public class Test3 {
    public static void main(String[] args) {

    }

}
