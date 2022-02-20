package panyujie.practice.work1.demo2;

import java.awt.*;

public class TestDemo{
    public static void main(String[] args){

		 Circle circle=new Circle(2.0);
		 Triangle triangle=new Triangle(1.0, 2.0);
		 Ladder ladder=new Ladder(3.0, 2.0,3.0);

	     Geometry[] g=new Geometry[]{circle,triangle,ladder};

		Geometry geometry=new Circle(2);
		System.out.println(geometry.getArea());

		//double sum=AreaCompute.areaSum(g);
        //double avg=AreaCompute.areaAvg(g);

       	//System.out.printf("AreaSum=%f\n", sum);
      
    } 
}
