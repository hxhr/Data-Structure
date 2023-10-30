#include <iostream>
#include <list>
#include <vector>
using namespace std;

// ����һ���ṹ���ʾ����ʽ�Ľڵ㣬���а���ϵ����ָ����
struct Node {
    int coef;  // ϵ��
    int exp;   // ָ��
    // �ṹ��Ĺ��캯�������ڳ�ʼ��
    Node(int c, int e) : coef(c), exp(e) {}
};

// ����������ʽ���
list<Node> add(const list<Node>& A, const list<Node>& B) {
    list<Node> result;  // ����Ķ���ʽ
    auto itA = A.begin(), itB = B.begin();
    // ����������ʽ��δ������ʱ
    while (itA != A.end() && itB != B.end()) {
        if (itA->exp == itB->exp) {  // ָ����ͬ
            int sum_coef = itA->coef + itB->coef;  // ϵ�����
            if (sum_coef) {  // ���ϵ���Ͳ�Ϊ0
                result.push_back(Node(sum_coef, itA->exp));
            }
            itA++, itB++;
        }
        else if (itA->exp < itB->exp) {  // A��ָ��С��B
            result.push_back(*itA);
            itA++;
        }
        else {  // B��ָ��С��A
            result.push_back(*itB);
            itB++;
        }
    }
    // ���Aδ�����꣬��ʣ�ಿ����ӵ����
    while (itA != A.end()) result.push_back(*itA++);
    // ���Bδ�����꣬��ʣ�ಿ����ӵ����
    while (itB != B.end()) result.push_back(*itB++);
    return result;
}

// ����������ʽ���
list<Node> multiply(const list<Node>& A, const list<Node>& B) {
    // ʹ��һ��������洢��ʱ�ĳ˷����
    vector<int> temp(4100, 0); // max size is 2050 * 2

    // ����A��ÿһ���B��ÿһ�������ˣ�������temp����
    for (const auto& termA : A) {
        for (const auto& termB : B) {
            temp[termA.exp + termB.exp] += termA.coef * termB.coef;
        }
    }

    list<Node> result;  // ����Ķ���ʽ
    for (int i = 0; (unsigned int)i < temp.size(); i++) {
        if (temp[i] != 0) {
            result.push_back(Node(temp[i], i));
        }
    }
    return result;
}

int main() {
    int m, n, op;
    cin >> m;
    list<Node> poly1, poly2;
    // �����һ������ʽ
    for (int i = 0; i < m; i++) {
        int coef, exp;
        cin >> coef >> exp;
        poly1.push_back(Node(coef, exp));
    }
    cin >> n;
    // ����ڶ�������ʽ
    for (int i = 0; i < n; i++) {
        int coef, exp;
        cin >> coef >> exp;
        poly2.push_back(Node(coef, exp));
    }
    cin >> op;  // �������ѡ��

    // ���ݲ���ѡ��������㲢���
    if (op == 0 || op == 2) {  // �ӷ��������߶�Ҫ
        list<Node> sum = add(poly1, poly2);
        for (const Node& term : sum) {
            cout << term.coef << " " << term.exp << " ";
        }
        cout << endl;
    }
    if (op == 1 || op == 2) {  // �˷��������߶�Ҫ
        list<Node> prod = multiply(poly1, poly2);
        for (const Node& term : prod) {
            cout << term.coef << " " << term.exp << " ";
        }
        cout << endl;
    }

    return 0;
}
