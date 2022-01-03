package com.bit.demo1;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Submerge
 * Date: 2021-12-31
 * Time: 14:33
 */
public class Dog extends Animal { //继承
    public Dog(){

    }
    public Dog(String name, int age) {
        super(name, age);//调用父类的两个参数的方法
    }

    @Override
    public void eat() {
        System.out.println(name+"狼吞虎咽的吃");
    }
}
