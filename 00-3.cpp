#include <iostream>
#include <utility>//pair
#include<string>
using namespace std;

//�����庯����main�ⶼ����
pair<long long, long long> num(int n)
{
	if (n == 0) {
		return{ 0,1 };
	}
	pair<long long, long long> pre = num(n - 1);

	long long male = pre.first + pre.second;
	long long female = pre.first+1;
	return{ male,female };//���￨�˺þã���Ϊһ��ʼֱ�ӷ������������ǵݹ�ʱ����
}
//1 2
//3 2
//


int main()
{

	//�õݹ���ô���
	int sum[60] = { 0 };
	for (int i = 0;; i++) {
		cin >> sum[i];
		if (sum[i] == -1) {
			break;
		}

	}

	for (int i = 0; sum[i] != -1; i++) {
		cout << num(sum[i]).first << " " << num(sum[i]).second + num(sum[i]).first << endl;
	}
	
	


}