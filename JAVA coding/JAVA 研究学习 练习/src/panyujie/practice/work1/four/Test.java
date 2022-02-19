package panyujie.practice.work1.four;

import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Submerge
 * Date: 2022-02-17
 * Time: 13:34
 */

public class Test {

    public static double div(double a ,double b){ //减
        return a/b;
    }

    public static double add(double a ,double b){ //加
        return a+b;
    }
    public static double sub(double a ,double b){ //减
        return a-b;
    }
    public static double mul(double a ,double b){ //乘
        return a*b;
    }

    public static void main(String[] args) {

        Scanner sc=new Scanner(System.in);

        System.out.println("请输入两个数，实现四则运算");

        double x=sc.nextDouble();
        double y=sc.nextDouble();

        System.out.println(add(x, y));
        System.out.println(sub(x, y));
        System.out.println(mul(x, y));
        System.out.println(div(x, y));
    }

}
