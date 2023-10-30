#include <iostream>
#include <deque>
#include <string>
using namespace std;


//
//Ϊ��ʵ��GetMax()�����ĸ�Ч�����ǿ���ʹ��һ��˫�˶��У�deque�����������Ǵ洢�����е����ֵ��
//
//���巽�����£�
//
//ʹ���������У�һ������q������������Ӻͳ��Ӳ�������һ������max_deque���ڴ洢�����е����ֵ��
//��һ����Ԫ�����ʱ��������ӵ�q���е�β����ͬʱ����max_deque��β����ʼ��ɾ������С�����Ԫ�ص�Ԫ�أ�Ȼ����Ԫ����ӵ�max_deque��β������ȷ����max_deque��ͷ������q�е�ǰ����Ԫ�ء�
//��һ��Ԫ�س���ʱ��������Ԫ���Ƿ���max_deque��ͷ��������ǵĻ�Ҳ��max_deque��ɾ������
//GetMax()ֻ��Ҫ����max_deque��ͷ��Ԫ�ء�

//���ַ�������ȷ��GetMax()������ʱ�临�Ӷ�ΪO(1)�����ң���Ȼÿ����Ӻͳ��Ӳ��������漰���push_back()��pop_front()��
//������ÿ��Ԫ��ֻ�ᱻpush_back()��pop_front()һ�Σ�������Щ������̯��ʱ�临�Ӷ���Ȼ��O(1)��

int main() {
    int n;
    cin >> n;

    deque<int> q;  // ������
    deque<int> max_deque;  // �������У��洢���ֵ

    string op;
    while (cin >> op) {
        if (op == "quit") {
            break;
        }
        else if (op == "enqueue") {
            if (q.size() == n) {
                cout << "Queue is Full" << endl;
            }
            else {
                int val;
                cin >> val;
                q.push_back(val);
                while (!max_deque.empty() && max_deque.back() < val) {
                    max_deque.pop_back();
                }
                max_deque.push_back(val);
            }
        }
        else if (op == "dequeue") {
            if (q.empty()) {
                cout << "Queue is Empty" << endl;
            }
            else {
                int front_val = q.front();
                q.pop_front();
                if (front_val == max_deque.front()) {
                    max_deque.pop_front();
                }
                cout << front_val << endl;
            }
        }
        else if (op == "max") {
            if (q.empty()) {
                cout << "Queue is Empty" << endl;
            }
            else {
                cout << max_deque.front() << endl;
            }
        }
    }

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop_front();
    }
    cout << endl;

    return 0;
}
