package panyujie.practice.work1.demo2;

public class AreaCompute {
    public static double areaSum(Geometry[] array) {
        double sum = 0.0;
        for (Geometry geometry : array) {
            sum += geometry.getArea();
        }
        return sum;
    }

    public static double areaAvg(Geometry[] array) {
        double sum=areaSum(array);
        return sum/array.length;
    }

}
