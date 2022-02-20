package panyujie.practice.work1.demo2;
class Triangle extends  Geometry{
    private double bottom,height; 
    public Triangle(){
    }
    public Triangle(double b,double h){
    	 this.bottom=b; 
     	 this.height=h;  	
    }  
    
    public  double getArea(){
    	return bottom*height/2;
    }  
    public String getName(){
    	return "Triangle";
    }
    
}
 