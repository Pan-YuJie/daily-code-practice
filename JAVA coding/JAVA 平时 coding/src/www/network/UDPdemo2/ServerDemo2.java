package www.network.UDPdemo2;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Submerge
 * Date: 2022-02-16
 * Time: 20:15
 */

import java.net.DatagramPacket;
import java.net.DatagramSocket;

/**
 * 接收端
 * 一直收数据
 */

public class ServerDemo2 {
    public static void main(String[] args) throws Exception {
        //1.创建接收端对象,注册端口
        DatagramSocket socket=new DatagramSocket(9999);

        //数据包 盘子
        byte[] buffer=new byte[1024*64];//64KB
        DatagramPacket packet=new DatagramPacket(buffer, buffer.length);

        while (true) {
            //接受 数据
            socket.receive(packet);

            //取数据
            int len=packet.getLength();
            String res=new String(buffer,0,len);
            System.out.println("收到了来自："+packet.getAddress()+"对方端口是"+packet.getPort()+"的消息：\n"+res);

        }

    }

}
