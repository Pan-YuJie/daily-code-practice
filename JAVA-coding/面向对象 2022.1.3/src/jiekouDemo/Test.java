package jiekouDemo;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Submerge
 * Date: 2022-01-03
 * Time: 13:59
 */

//接口种不能有具体实现 , 非要有具体实现只能通过关键字default来修饰方法 或者  静态方法(static)
//接口种所有方法默认 public
//接口种的方法默认 public abstract
//接口是不能被new关键字类实例化的
//类和接口间的关系是通过 implements 来实现的
//当一个类实现了一个接口，必须重写接口当中的抽象方法


class Rect implements IShape{
    @Override
    public void draw() {
        System.out.println("♦");
    }

    @Override
    public void func() {
        System.out.println("重写接口的默认方法");
    }
}

class Flower implements IShape {
    public void draw() {
        System.out.println("❀");
    }
}

interface IShape{  //接口 使用interface修饰

    abstract public void draw();//void draw;
    default public void func(){
    }



}

public class Test {

    public static void drawMap(IShape shape){
        shape.draw();
    }

    public static void main(String[] args) {
        Rect rect=new Rect();
        drawMap(rect);

        Flower flower= new Flower();
        drawMap(flower);

    }

    public static void main1(String[] args) {
        IShape iShape=new Rect();
        iShape.draw();
    }
}
