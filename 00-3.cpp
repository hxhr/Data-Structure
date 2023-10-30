#include <iostream>
#include <utility>//pair
#include<string>
using namespace std;

//连定义函数在main外都忘了
pair<long long, long long> num(int n)
{
	if (n == 0) {
		return{ 0,1 };
	}
	pair<long long, long long> pre = num(n - 1);

	long long male = pre.first + pre.second;
	long long female = pre.first+1;
	return{ male,female };//这里卡了好久，因为一开始直接返回总数，但是递归时不是
}
//1 2
//3 2
//


int main()
{

	//用递归最好处理
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