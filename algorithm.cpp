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
//�����������ص㣺1����ȫ��������2�����ڵ�������ӽڵ��
void jiandui(int arr[], int start, int end)
{
	//�������ڵ�ָ����ӽڵ�ָ��
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end)  //���ӽڵ�ָ���ڷ�Χ�ڲ����Ƚ�
	{
		if (son + 1 <= end && arr[son] < arr[son + 1]) //�ȱȽ������ӽڵ��С��ѡ������
			son++;
		if (arr[dad] > arr[son]) //������ڵ����ӽڵ���������ϣ�ֱ����������
			return;
		else  //���򽻻����������ټ����ӽڵ����ڵ�Ƚ�
		{
			std::swap(arr[dad], arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}
void dui(int arr[], int len)
{
	//��ʼ����i������һ�����ڵ㿪ʼ����
	for (int i = len / 2 - 1; i >= 0; i--)
		jiandui(arr, i, len - 1);
	//�Ƚ���һ��Ԫ�غ��Ѿ��źõ�Ԫ��ǰһλ���������ٴ��µ���(�յ�����Ԫ��֮ǰ��Ԫ��)��ֱ���������
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
		/*���������ұ�key���ֵ*/
		while (arr[++i] < key)
		{
			if (i == high) {
				break;
			}
		}
		/*���������ұ�keyС��ֵ*/
		while (arr[--j] > key)
		{
			if (j == low) {
				break;
			}
		}
		if (i >= j) break;
		/*����i,j��Ӧ��ֵ*/
		std::swap(arr[i], arr[j]);
	}
	/*����ֵ��j��Ӧֵ����*/
	std::swap(arr[low], arr[j]);
	kuaisu(arr, low, j - 1);
	kuaisu(arr, j + 1, high);
}

void merge(int* data, int start, int mid, int end, int* result)
{
	int i, j, k;
	i = start;
	j = mid + 1;                        //�����ظ��Ƚ�data[mid]
	k = 0;
	while (i <= mid && j <= end)        //����data[start,mid]������(mid,end]��û��ȫ����������result��ȥ
	{
		if (data[i] <= data[j])         //���data[i]С�ڵ���data[j]
			result[k++] = data[i++];    //��data[i]��ֵ����result[k]��֮��i,k����һ����ʾ����һλ
		else
			result[k++] = data[j++];    //���򣬽�data[j]��ֵ����result[k]��j,k����һ
	}
	while (i <= mid)                    //��ʾ����data(mid,end]�Ѿ�ȫ������result������ȥ�ˣ�������data[start,mid]����ʣ��
		result[k++] = data[i++];        //������data[start,mid]ʣ�µ�ֵ����һ��������result
	while (j <= end)                    //��ʾ����data[start,mid]�Ѿ�ȫ�����뵽result������ȥ�ˣ�������(mid,high]����ʣ��
		result[k++] = data[j++];        //������a[mid,high]ʣ�µ�ֵ����һ��������result

	for (i = 0; i < k; i++)             //���鲢��������ֵ��һ��������data[start,end]
		data[start + i] = result[i];    //ע�⣬Ӧ��data[start+i]��ʼ��ֵ
}
void guibing(int* data, int start, int end, int* result)
{
	if (start < end)
	{
		int mid = start + (end - start) / 2;  //�������int
		guibing(data, start, mid, result);    //����߽�������
		guibing(data, mid + 1, end, result);  //���ұ߽�������
		merge(data, start, mid, end, result); //������õ����ݺϲ�
	}
}

void xier(int head[], int num)
{
	int i, j, d;
	int tmp;
	d = num / 2;//��������
	while (d > 0)//����
	{
		for (i = d; i < num; i++)//�����������ֱ�Ӳ�������
		{
			j = i - d;
			while (j >= 0 && head[i] < head[j])
			{
				std::swap(head[j], head[i]);
				i = i - d;
				j = j - d;
			}
		}
		d = d / 2;//��С����
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
