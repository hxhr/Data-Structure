#include <iostream>
using namespace std;
////此为递归版本
//int fin(int n, int m)
//{
//	if (n == 1) {
//		return 0;
//	}
//	
//	return (fin(n - 1, m) + m) % n;
//}


//用迭代代替递归
int fin(int n, int m) {
	int result = 0;  // 初始化为 f(1,m) 的值
	for (int i = 2; i <= n; i++) {
		result = (result + m) % i;
	}
	return result;
}

int main()
{
	//1、递推公式：f(n,m)=(f(n−1,m)+m)%n
	//2、使用递归函数会占用较多的内存，当递归层次太深时可能导致程序不能执行。
	int m = 0;
	int n = 0;
	cin >> n;
	cin >> m;
	cout << fin(n, m);
	
}