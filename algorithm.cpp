#include "algorithm.h"

void maopao(int head[],int num)
{
	for (int i = num-1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (head[j] > head[j+1] ) {
				std::swap(head[j],head[j + 1]);
			}
		}
	}
}

void maopaoImprove1(int head[], int num)
{
	for (int i = num - 1; i > 0; i--) {
		bool flag = true;
		for (int j = 0; j < i; j++) {
			if (head[j] > head[j + 1]) {
				std::swap(head[j], head[j + 1]);
				flag = false;
			}
		}
		if (flag) break;
	}
}

void maopaoImprove2(int head[], int num)
{
	for (int i = num - 1; i > 0; i--) {
		int end = 0;
		bool flag = true;
		for (int j = 0; j < i; j++) {
			if (head[j] > head[j + 1]) {
				std::swap(head[j], head[j + 1]);
				flag = false;
				end = j+1;
			}
		}
		i = end;
		if (flag) break;
	}
}

void xuanze(int head[], int num)
{
	for (int i = num - 1; i > 0; i--) {
		int Max = 0;
		for (int j = 1; j <= i; j++) {
			if (head[Max] < head[j]) {
				Max = j;
			}
		}
		std::swap(head[i], head[Max]);
	}
	
}
//堆排序两个特点：1、完全二叉树，2、父节点比左右子节点大
void jiandui(int arr[], int start, int end)
{
	//建立父节点指标和子节点指标
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end)  //若子节点指标在范围内才做比较
	{
		if (son + 1 <= end && arr[son] < arr[son + 1]) //先比较两个子节点大小，选择最大的
			son++;
		if (arr[dad] > arr[son]) //如果父节点大於子节点代表调整完毕，直接跳出函数
			return;
		else  //否则交换父子内容再继续子节点和孙节点比较
		{
			std::swap(arr[dad], arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}
void dui(int arr[], int len)
{
	//初始化，i从最後一个父节点开始调整
	for (int i = len / 2 - 1; i >= 0; i--)
		jiandui(arr, i, len - 1);
	//先将第一个元素和已经排好的元素前一位做交换，再从新调整(刚调整的元素之前的元素)，直到排序完毕
	for (int i = len - 1; i > 0; i--)
	{
		std::swap(arr[0], arr[i]);
		jiandui(arr, 0, i - 1);
	}
}

void charu(int head[], int num)
{
	for (int i = 1; i < num; i++) {
		int current = i;
		while (current > 0 && head[current] < head[current - 1]) {
			std::swap(head[current], head[current - 1]);
			current--;
		}
	}
}

void kuaisu(int arr[], int low,int high)
{
	if (high <= low) return;
	int i = low;
	int j = high + 1;
	int key = arr[low];
	while (true)
	{
		/*从左向右找比key大的值*/
		while (arr[++i] < key)
		{
			if (i == high) {
				break;
			}
		}
		/*从右向左找比key小的值*/
		while (arr[--j] > key)
		{
			if (j == low) {
				break;
			}
		}
		if (i >= j) break;
		/*交换i,j对应的值*/
		std::swap(arr[i], arr[j]);
	}
	/*中枢值与j对应值交换*/
	std::swap(arr[low], arr[j]);
	kuaisu(arr, low, j - 1);
	kuaisu(arr, j + 1, high);
}

void merge(int* data, int start, int mid, int end, int* result)
{
	int i, j, k;
	i = start;
	j = mid + 1;                        //避免重复比较data[mid]
	k = 0;
	while (i <= mid && j <= end)        //数组data[start,mid]与数组(mid,end]均没有全部归入数组result中去
	{
		if (data[i] <= data[j])         //如果data[i]小于等于data[j]
			result[k++] = data[i++];    //则将data[i]的值赋给result[k]，之后i,k各加一，表示后移一位
		else
			result[k++] = data[j++];    //否则，将data[j]的值赋给result[k]，j,k各加一
	}
	while (i <= mid)                    //表示数组data(mid,end]已经全部归入result数组中去了，而数组data[start,mid]还有剩余
		result[k++] = data[i++];        //将数组data[start,mid]剩下的值，逐一归入数组result
	while (j <= end)                    //表示数组data[start,mid]已经全部归入到result数组中去了，而数组(mid,high]还有剩余
		result[k++] = data[j++];        //将数组a[mid,high]剩下的值，逐一归入数组result

	for (i = 0; i < k; i++)             //将归并后的数组的值逐一赋给数组data[start,end]
		data[start + i] = result[i];    //注意，应从data[start+i]开始赋值
}
void guibing(int* data, int start, int end, int* result)
{
	if (start < end)
	{
		int mid = start + (end - start) / 2;  //避免溢出int
		guibing(data, start, mid, result);    //对左边进行排序
		guibing(data, mid + 1, end, result);  //对右边进行排序
		merge(data, start, mid, end, result); //把排序好的数据合并
	}
}

void xier(int head[], int num)
{
	int i, j, d;
	int tmp;
	d = num / 2;//设置增量
	while (d > 0)//出口
	{
		for (i = d; i < num; i++)//对所有组采用直接插入排序
		{
			j = i - d;
			while (j >= 0 && head[i] < head[j])
			{
				std::swap(head[j], head[i]);
				i = i - d;
				j = j - d;
			}
		}
		d = d / 2;//减小增量
	}
}

void js(int head[],int num , int indexLen , int Max , int Min)
{
	int* arr1 = new int[indexLen];
	for (int i = 0; i < indexLen; i++) {
		arr1[i] = 0;
	}
	int* arr2 = new int[num];
	for (int i = 0; i < num; i++) {
		arr1[head[i] - Min]++;
	}
	for (int i = 1; i < indexLen; i++) {
		arr1[i] += arr1[i - 1];
	}
	for (int i = num - 1; i >= 0; i--) {
		arr2[arr1[head[i] - Min] - 1] = head[i];
		arr1[head[i] - Min]--;
	}
	for (int i = 0; i < num; i++) {
		head[i] = arr2[i];
	}
}
void jishu(int head[], int num)
{
	int Min = head[0];
	int Max = head[0];
	int indexLen = 0;
	for (int i = 1; i < num; i++) {
		if (head[i] < Min) Min = head[i];
		if (head[i] > Max) Max = head[i];
	}
	indexLen = Max - Min + 1;
	js(head, num, indexLen, Max, Min);

}
