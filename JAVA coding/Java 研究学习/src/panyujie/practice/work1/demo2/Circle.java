package panyujie.practice.work1.demo2;

class Circle extends Geometry {
    private double r;

    public Circle() {
    }
    public Circle(double r){
        this.r=r;
    }

    public  double getArea(){
        return 3.14*r*r;
    }
    public String getName(){
        return "Circle";
    }

}
