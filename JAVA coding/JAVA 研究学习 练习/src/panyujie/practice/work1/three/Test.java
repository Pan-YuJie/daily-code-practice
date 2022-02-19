package panyujie.practice.work1.three;

import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Submerge
 * Date: 2022-02-17
 * Time: 13:19
 */
public class Test {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n=0;
        n=sc.nextInt();
        double[] arr = new double[n];


        for (int i = 0; i < n; i++) {
          arr[i]= sc.nextDouble();
        }

        double max=arr[0];
        for (int i = 1; i < n; i++) {
            if(max<arr[i]){
                max= arr[i];
            }
        }

        System.out.println(max);
    }
}
