#include <iostream>
#include"algorithm.h"

using namespace std;

int main() {
	int num[10] = { 9,8,7,6,5,4,3,2,1,0};
	int len = sizeof(num) / sizeof(int);
	//maopao(num, len);
	//����һ����־λ���жϵ�ǰѭ����û�иı�λ�ã����û�У�˵����������ֱ���˳���
	//maopaoImprove1(num, len); 
	//����һ����־����¼��ǰð��֮�����һ�α任��β��λ�ã�Ȼ�󽫴�λ�ø�ֵ�����ѭ�������ֵ����ʱ�ռ临�Ӷ����Ϊn^2,���Ϊn
	//maopaoImprove2(num, len);
	//ѡ������ʱ�临�Ӷ�Ϊn^2��ѡ�������˼����Ѱ�����ֵ��Ȼ���滻��ĩβ��Ԫ�أ��������ܹ��Ż�Ѱ�����ֵ��һ����
	//xuanze(num, len);
	//�������ʱ�临�Ӷ�Ϊn*logn
	//dui(num, len);
	//������������ʱ�临�Ӷ�Ϊn�������������ʱ������ʱ�临�Ӷ�Ϊn^2
	//charu(num, len);
	//��������ĺ���˼�������÷ֶ���֮��ʱ�临�Ӷ�Ϊnlogn
	//kuaisu(num, 0,len-1);
	//�鲢����
	/*int* result = new int[10];
	guibing(num,0,len-1,result);
	for (int i = 0; i < len; i++) {
		cout << num[i] << endl;
	}
	delete[]result;*/
	//ϣ������ĺ���˼���ǲ����������ȱȽ�2����Ȼ��Ƚ�4��...
	//xier(num,len);
	//jishu(num, len);
	for(int i = 0; i < len; i++) {
		cout << num[i] << endl;
	}
	return 0;
}