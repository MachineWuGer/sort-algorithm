#include <iostream>
#include"algorithm.h"

using namespace std;

int main() {
	int num[10] = { 9,8,7,6,5,4,3,2,1,0};
	int len = sizeof(num) / sizeof(int);
	//maopao(num, len);
	//建立一个标志位，判断当前循环有没有改变位置，如果没有，说明整体有序，直接退出。
	//maopaoImprove1(num, len); 
	//建立一个标志，记录当前冒泡之后最后一次变换的尾部位置，然后将此位置赋值给外层循环的最大值。此时空间复杂度最差为n^2,最好为n
	//maopaoImprove2(num, len);
	//选择排序时间复杂度为n^2，选择排序的思想是寻找最大值，然后替换最末尾的元素，堆排序能够优化寻找最大值这一过程
	//xuanze(num, len);
	//堆排序的时间复杂度为n*logn
	//dui(num, len);
	//插入排序的最佳时间复杂度为n，当整体有序的时候，最差的时间复杂度为n^2
	//charu(num, len);
	//快速排序的核心思想是利用分而治之，时间复杂度为nlogn
	//kuaisu(num, 0,len-1);
	//归并排序
	/*int* result = new int[10];
	guibing(num,0,len-1,result);
	for (int i = 0; i < len; i++) {
		cout << num[i] << endl;
	}
	delete[]result;*/
	//希尔排序的核心思想是插入排序，首先比较2个，然后比较4个...
	//xier(num,len);
	//jishu(num, len);
	for(int i = 0; i < len; i++) {
		cout << num[i] << endl;
	}
	return 0;
}