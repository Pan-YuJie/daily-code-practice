/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Submerge
 * Date: 2022-01-03
 * Time: 12:57
 * @author Submerge
 */

class Shape{
    public void draw(){
        System.out.println("draw()");
    }

}

class Rect extends Shape{
    public void draw(){
        System.out.println("♦");
    }
}

class Flower extends Shape{
    public void draw() {
        System.out.println("❀");
    }
}

public class Text {

    public static void drawMap(Shape shape){
        shape.draw();
    }

    public static void main(String[] args) {
        Rect rect=new Rect();
        drawMap(rect);
        Flower flower=new Flower();
        drawMap(flower);

    }

    public static void main1(String[] args) {
        Shape shape1 =new Rect();
        shape1.draw();

        Shape shape2 = new Flower();
        shape2.draw();



    }

}
