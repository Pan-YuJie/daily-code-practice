package com.bit.demo1;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Submerge
 * Date: 2021-12-31
 * Time: 14:33
 */
public class Bird extends Animal {
    String wing;
    public Bird(){
    }
    public Bird(String name, int age, String wing) {
        super(name, age);
        this.wing = wing;
    }
    public void fly() {
        System.out.println("飞");
    }
}
