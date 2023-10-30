#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    // 声明变量
    double sum = 0.0;
    double income;

    // 从用户处读取12个月的收入
    for (int i = 0; i < 12; i++) {
        cin >> income;
        sum += income;
    }

    // 计算平均值
    double average = sum / 12;

    // 输出平均值，精确到分
    cout << "¥" << fixed << setprecision(2) << average <<endl;

    return 0;
}
