package demo4;

import java.util.Arrays;
import java.util.Comparator;
import java.util.SortedMap;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Submerge
 * Date: 2022-01-03
 * Time: 15:28
 */

//comparable接口 缺点很大：对类的入侵性很强，一旦写好不敢轻易改动

/*class Student implements Comparable<Student>{
    public int age;
    public String name;
    public  double score;

    public Student(int age, String name, double score) {
        this.age = age;
        this.name = name;
        this.score = score;
    }

    //compareTo只能用一次，不能兼几种其他的比较
    @Override
    public int compareTo(Student o) {
        if(this.age>o.age){
            return 1;
        }else if(this.age==o.age){
            return 0;
        }else{
            return -1;
        }
    }

    @Override
    public String toString() {
        return "Student{" +
                "age=" + age +
                ", name='" + name + '\'' +
                ", score=" + score +
                "}";
    }
}*/

class Student implements Comparable<Student>{
    public int age;
    public String name;
    public  double score;

    public Student(int age, String name, double score) {
        this.age = age;
        this.name = name;
        this.score = score;
    }

    //compareTo只能用一次，不能兼几种其他的比较
    @Override
    public int compareTo(Student o) {
        if(this.age>o.age){
            return 1;
        }else if(this.age==o.age){
            return 0;
        }else{
            return -1;
        }
    }

    @Override
    public String toString() {
        return "Student{" +
                "age=" + age +
                ", name='" + name + '\'' +
                ", score=" + score +
                "}";
    }
}

class AgeComparator implements Comparator<Student>{
    public int compare(Student o1, Student o2){
        return o1.age-o2.age;
    }
}

class ScoreComparator implements Comparator<Student>{
    @Override
    public int compare(Student o1, Student o2) {
        return (int)(o1.score- o2.score);
    }
}

class NameComparator implements  Comparator<Student>{
    public int compare(Student o1,Student o2){
        return o1.name.compareTo(o2.name);
    }
}

public class Test {

    public static void main3(String[] args) {
        Student student1=new Student(12,"bit",99.99);
        Student student2=new Student(55,"hhh",66.98);

        AgeComparator ageComparator=new AgeComparator();
        System.out.println(ageComparator.compare(student1, student2));

    }
    public static void main(String[] args) {
        Student[] student=new Student[3];
        AgeComparator ageComparator=new AgeComparator();
        NameComparator nameComparator=new NameComparator();
        ScoreComparator scoreComparator=new ScoreComparator();

        student[0]=new Student(12,"bit",99.99);
        student[1]=new Student(55,"hhh",66.98);
        student[2]=new Student(34,"abc",79.6);
        System.out.println(Arrays.toString(student));

        Arrays.sort(student,ageComparator);//默认小到大
        System.out.println(Arrays.toString(student));


        Arrays.sort(student,scoreComparator);//默认小到大
        System.out.println(Arrays.toString(student));


        Arrays.sort(student,nameComparator);//默认小到大
        System.out.println(Arrays.toString(student));
    }

    public static void main1(String[] args) {
        int[] array={5,3,6,9,21,45,78,343,66};
        Arrays.sort(array);
        System.out.println(Arrays.toString(array));

    }

}
