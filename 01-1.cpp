#include <iostream>
#include <vector>
using namespace std;

// ������һ����ת���������ڵ�ǰ�����б�ע�͵���
// ����������������start��end�Ĳ��ֽ��з�ת
//void reverse(vector<int>& nums, int start, int end) {
//    while (start < end) {
//        swap(nums[start], nums[end]);  // ����start��endλ���ϵ�ֵ
//        start++;  // ��start����
//        end--;    // ��end����
//    }
//}
 // ������һ����ע�͵���ͨ����תʵ��������ת�ķ���
    // ʹ�÷�ת���������������ƶ�k��λ��
    /*
    reverse(nums, 0, n - 1);    // ���ȷ�ת��������
    reverse(nums, 0, k - 1);    // Ȼ��תǰk��Ԫ��
    reverse(nums, k, n - 1);    // ���תʣ���Ԫ��
    */

int main() {
    int n, k;  // n���ڱ�������ĳ��ȣ�k���ڱ������Ƶ�λ����
    cin >> n >> k;  // �ӱ�׼�����ȡn��k��ֵ

    k %= n;  // Ϊ��ȷ���ƶ���λ��������������ĳ��ȣ�����ȡ�����

    vector<int> nums(n);  // ����һ����������nums����СΪn
    for (int i = 0; i < n; i++) {
        cin >> nums[i];  // �ӱ�׼�����ȡn���������浽nums��
    }

    // ʹ��ѭ���滻������������ת
    int count = 0;  // ��¼�Ѿ������Ԫ������
    for (int start = 0; count < n; start++) {
        int current = start;     // ��ǰҪ�����λ��
        int prev = nums[start];  // ��ǰλ���ϵ�Ԫ��ֵ
        do {
            int next = (current + k) % n;  // ���㵱ǰԪ��Ӧ���Ƶ�����λ��
            swap(nums[next], prev);  // ����ǰλ�õ�Ԫ������λ�õ�Ԫ�ؽ��н���
            current = next;  // ���µ�ǰ�����λ��
            count++;  // �����Ѵ����Ԫ������
        } while (start != current);  // ��start����currentʱ��һ��ѭ����ɣ��˳�do-whileѭ��
    }

    // �����ת�������
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";  // ���ÿһ��Ԫ�أ�֮���ÿո����
    }

    return 0;  // �������������0
}
