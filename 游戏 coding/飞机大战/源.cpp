#include"标头.h"

int main() {
	initgraph(width, high);
	start();//初始化
	while (1) {
		show();
		updatewithoutinput();//无关
		updatewithinput();//有关
	}
	return 1;
}