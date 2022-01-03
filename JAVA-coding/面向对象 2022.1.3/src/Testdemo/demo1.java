package Testdemo;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Submerge
 * Date: 2022-01-03
 * Time: 13:23
 */

abstract class Shape{  //抽象类  只能被继承
    public int num;
    public void func(){
        System.out.println("测试方法");
    }
    public abstract void draw(); //抽象方法
}

class Flower extends Shape {
    @Override
    public void draw() {
        System.out.println("❀");
    }
}

class Rect extends Shape{  //普通类继承了一个抽象类，那么这个普通类当中。需要重写抽象类种所有方法
    @Override
    public void draw() {
        super.func();
        System.out.println("♦");
    }
}

abstract class A extends Shape{  // 一个抽象类继承一个抽象类  A继承B 可以不实现抽象方法
    public abstract void funcA();

}

class B extends A{ // 当一个已经继承抽象类的抽象类，必须实现前两个抽象类的所有抽象方法

    @Override
    public void draw() {

    }

    @Override
    public void funcA() {

    }
}

abstract class AA{
    private String name;

    public AA(String name) {
        this.name=name;
    }

    public String getName(){
        return this.name;
    }
    public abstract void func();

}

class BB extends AA{

    BB(String name){
        super(name);
    }

    @Override
    public void func() {

    }
}

public class demo1 {

    public static void drawMap(Shape shape){
        shape.draw();
    }

    public static void main(String[] args) {

    }

    public static void main1(String[] args) {
        // Shape shape =new Shape() ; 抽象类不能被实例化 new
        Shape shape=new Flower();
        drawMap(shape);
        Rect rect=new Rect();
        drawMap(rect);

    }
}
