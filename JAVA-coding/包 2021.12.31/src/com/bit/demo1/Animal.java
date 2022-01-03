package com.bit.demo1;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Submerge
 * Date: 2021-12-31
 * Time: 13:36
 */
public class Animal {
    public String name;
    public int age;
    private int count;
    protected int idx;
    public Animal(){
    }

    public Animal(String name ,int age ){
        this.name=name;
        this.age=age;
    }

    public void eat(){
        System.out.println(name+"吃饭");
    }
}

