package panyujie.practice.work1.two;

import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Submerge
 * Date: 2022-02-17
 * Time: 13:16
 */

public class Test {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("请输入一个三位数：");

        int num = sc.nextInt();
        int g = num%10;
        int s = (num/10)%10;
        int b = num/100;
        int sum = (g*g*g)+(s*s*s)+(b*b*b);

        if(sum == num){
            System.out.println("该数为水仙花数！");
        }else
            System.out.println("该数不为水仙花数！");
    }
}
