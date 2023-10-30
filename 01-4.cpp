#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ʹ��vector<int>����ʾ����������vec[0]�Ǹ�λ��vec[1]��ʮλ
typedef vector<int> BigInt;

// �����ӷ�
BigInt add(const BigInt& a, const BigInt& b) {
    BigInt result;
    int carry = 0;
    size_t len = max(a.size(), b.size()); // size_t ����

    for (size_t i = 0; i < len || carry; ++i) {  // ʹ�� size_t ����
        int sum = carry;
        if (i < a.size()) sum += a[i];
        if (i < b.size()) sum += b[i];
        result.push_back(sum % 10);
        carry = sum / 10;
    }

    return result;
}
// ��������ͨ���ĳ˷�
BigInt multiply(const BigInt& a, int b) {
    BigInt result;
    int carry = 0;

    for (size_t i = 0; i < a.size() || carry; ++i) {  // ʹ�� size_t ����
        long long cur = carry + (i < a.size() ? static_cast<long long>(a[i]) * b : 0); // ʹ�� long long ����
        result.push_back(static_cast<int>(cur % 10));  // ʹ������ת��
        carry = static_cast<int>(cur / 10);  // ʹ������ת��
    }

    return result;
}

// ���㼶�� A + 2A^2 + 3A^3 + ... + NAN
BigInt calculateSeries(int N, int A) {
    BigInt result = { 0 }; // ��ʼ��Ϊ0
    BigInt powerOfA = { A }; // ����A^i�ĵ�ǰֵ

    for (int i = 1; i <= N; ++i) {
        // ����i*A^i
        BigInt current = multiply(powerOfA, i);
        // ������ӵ��ۻ�����
        result = add(result, current);
        // ����A^i��ֵΪ��һ����
        powerOfA = multiply(powerOfA, A);
    }

    return result;
}

int main() {
    int N, A;
    while (cin >> N >> A) {
        BigInt result = calculateSeries(N, A);
        // ��ӡ�����ע������Ƿ���ģ���Ϊvector��0λ���Ǹ�λ��
        for (int i = result.size() - 1; i >= 0; --i) {
            cout << result[i];
        }
        cout << endl;
    }
    return 0;
}
