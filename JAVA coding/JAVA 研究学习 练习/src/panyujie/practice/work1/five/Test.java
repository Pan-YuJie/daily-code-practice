package panyujie.practice.work1.five;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Submerge
 * Date: 2022-02-17
 * Time: 13:46
 */
public class Test {

    public static double computerShape(Shape shape){
        return shape.computerArea();
    }

    public static void main(String[] args) {
//        Triangle triangle =new Triangle(2,2);
//        Rectangle rectangle=new Rectangle(2,2);
//        Circle circle=new Circle(4.4);
//        Ladder ladder=new Ladder(2,2,2);
//
//        System.out.println(computerShape(rectangle));
//        System.out.println(computerShape(triangle));
//        System.out.println(computerShape(circle));
//        System.out.println(computerShape(ladder));


        //求n个Circle , new n 个 对象
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();

        double sum=0;

        for(int i = 0; i<n; i++){
            System.out.println("输入半径:");
            double m = sc.nextDouble();
            sum+=computerShape(new Circle(m));
        }

        System.out.println(sum);

        System.out.println("输入要求的图形数量");

        // 求n个 …… 面积
        n=sc.nextInt();

        double x, y, z;
        //Scanner sc = new Scanner(System.in);
        sum=0.0;
        for (int i = 0; i < n; i++) {
            System.out.println("1.长方形 2.梯形 3.三角形 4.圆");
            String s = sc.next();
            Shape shape=new Shape();
            if ("1".equals(s)) {
                System.out.println("输入长，宽");
                x = sc.nextDouble();
                y = sc.nextDouble();
                shape = new Rectangle(x, y);
            }
            if ("2".equals(s)) {
                System.out.println("输入高，下底，上底");
                x = sc.nextDouble();
                y = sc.nextDouble();
                z = sc.nextDouble();
                shape = new Ladder(x, y, z);
            }
            if ("3".equals(s)) {
                System.out.println("输入高，下底");
                x = sc.nextDouble();
                y = sc.nextDouble();
                shape = new Triangle(x, y);
            }
            if ("4".equals(s)) {
                System.out.println("输入半径");
                x = sc.nextDouble();
                shape=new Circle(x);
            }
            sum+=computerShape(shape);
        }

        System.out.println(sum);


    }

    }

class Shape{
    protected double area;

    Shape() {
    }

    public double getArea() {
        return area;
    }

    public void setArea(double area) {
        this.area = area;
    }

    public  double computerArea(){
        return this.area;
    }

    public double computerAllArea(){
        return 1;
    }

}

class Circle extends Shape{
    private double radius; //半径

    public  Circle(){
    }

    public Circle(double radius) {
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    @Override
    public double computerArea() {
        super.area= this.radius * this.radius * 3.14;
        return super.area;
    }

}

class Triangle extends Shape{

    private double height;
    private double base;

    public Triangle(double height, double base) {
        this.height = height;
        this.base = base;
    }

    public Triangle() {
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public double getBase() {
        return base;
    }

    @Override
    public double computerArea() {
        super.area=0.5*this.height*this.base;
        return super.area;
    }

}

class Rectangle extends Shape{
    private double length;
    private double weight;

    @Override
    public double computerArea() {
        super.area=this.length*this.weight;
        return super.area;
    }

    public Rectangle(double length, double weight) {
        this.length = length;
        this.weight = weight;
    }

    Rectangle(){

    }


    public double getLength() {
        return length;
    }

    public void setLength(double length) {
        this.length = length;
    }

    public double getWeight() {
        return weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }
}

class Ladder extends Shape{

    private double  height;
    private double lowBase;
    private double highBase;

    public Ladder(double height, double lowBase, double highBase) {
        this.height = height;
        this.lowBase = lowBase;
        this.highBase = highBase;
    }

    @Override
    public double computerArea() {
        super.area=(lowBase+highBase)*height/2;
        return super.area;
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public double getLowBase() {
        return lowBase;
    }

    public void setLowBase(double lowBase) {
        this.lowBase = lowBase;
    }

    public double getHighBase() {
        return highBase;
    }

    public void setHighBase(double highBase) {
        this.highBase = highBase;
    }
}

