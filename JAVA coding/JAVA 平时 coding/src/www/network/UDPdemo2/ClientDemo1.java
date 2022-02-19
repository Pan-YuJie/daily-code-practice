package www.network.UDPdemo2;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;

/**
 * 发送端反复发送数据
 *  1.创建 DatagramSocket 对象发送端对象
 *  2.使用 while 死循环不断接受用户输入，如果输入的是的exit退出程序
 *  3.如果不是exit ，把数据封装
 *  4. DatagramSocker的对象send方法发送数据包
 */

/*
   发送端
 */
public class ClientDemo1 {
    public static void main(String[] args) throws Exception {

        //1.创建发送端对象 ; 一个程序只有一个端口， 并发时修改端口
        DatagramSocket socket=new DatagramSocket(6666);

        //2.创建一个数据包封装数据
        //    public DatagramPacket(byte buf[], int length, netAddress address, int port);
        //参数一：封装要发送的数据（韭菜）
        //参数二：发送数据大小
        //参数三：服务端的IP地址
        //参数四：服务端的端口

        Scanner sc=new Scanner(System.in);
        while(true){

            String msg= sc.nextLine();
            if(msg.equals("exit")){
                System.out.println("离线成功");
                socket.close();
                break;
            }

            byte[] buffer=msg.getBytes();
            DatagramPacket packet=new DatagramPacket(buffer, buffer.length,InetAddress.getLocalHost(),9999);

            //发送数据出去
            socket.send(packet);
        }

    }
}
