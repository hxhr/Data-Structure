#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 使用vector<int>来表示大数，其中vec[0]是个位，vec[1]是十位
typedef vector<int> BigInt;

// 大数加法
BigInt add(const BigInt& a, const BigInt& b) {
    BigInt result;
    int carry = 0;
    size_t len = max(a.size(), b.size()); // size_t 类型

    for (size_t i = 0; i < len || carry; ++i) {  // 使用 size_t 类型
        int sum = carry;
        if (i < a.size()) sum += a[i];
        if (i < b.size()) sum += b[i];
        result.push_back(sum % 10);
        carry = sum / 10;
    }

    return result;
}
// 大数和普通数的乘法
BigInt multiply(const BigInt& a, int b) {
    BigInt result;
    int carry = 0;

    for (size_t i = 0; i < a.size() || carry; ++i) {  // 使用 size_t 类型
        long long cur = carry + (i < a.size() ? static_cast<long long>(a[i]) * b : 0); // 使用 long long 类型
        result.push_back(static_cast<int>(cur % 10));  // 使用类型转换
        carry = static_cast<int>(cur / 10);  // 使用类型转换
    }

    return result;
}

// 计算级数 A + 2A^2 + 3A^3 + ... + NAN
BigInt calculateSeries(int N, int A) {
    BigInt result = { 0 }; // 初始化为0
    BigInt powerOfA = { A }; // 保存A^i的当前值

    for (int i = 1; i <= N; ++i) {
        // 计算i*A^i
        BigInt current = multiply(powerOfA, i);
        // 将结果加到累积和中
        result = add(result, current);
        // 更新A^i的值为下一个数
        powerOfA = multiply(powerOfA, A);
    }

    return result;
}

int main() {
    int N, A;
    while (cin >> N >> A) {
        BigInt result = calculateSeries(N, A);
        // 打印结果，注意输出是反向的，因为vector的0位置是个位数
        for (int i = result.size() - 1; i >= 0; --i) {
            cout << result[i];
        }
        cout << endl;
    }
    return 0;
}
