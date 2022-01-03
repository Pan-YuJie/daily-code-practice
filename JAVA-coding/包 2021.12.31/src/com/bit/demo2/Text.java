package com.bit.demo2;

import com.bit.demo1.Animal;
import com.bit.demo1.Bird;
import com.bit.demo1.Dog;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Submerge
 * Date: 2021-12-31
 * Time: 14:51
 */
public class Text {
    public static void main(String[] args) {
        Animal animal =new Dog("hhh",11);
        System.out.println(animal.age);
        animal.eat();//动态绑定
        //父类引用子类的对象
        //通过父类引用和子类同名的覆盖方法--》重写
        //                 1.方法名相同 2.参数相同 3.返回值相同 4.父子类

    }
}
