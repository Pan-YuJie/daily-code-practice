#include"��ͷ.h"

int main() {
	initgraph(width, high);
	start();//��ʼ��
	while (1) {
		show();
		updatewithoutinput();//�޹�
		updatewithinput();//�й�
	}
	return 1;
}