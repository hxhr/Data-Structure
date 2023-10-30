#include <iostream>
#include <list>
#include <vector>
using namespace std;

// 定义一个结构体表示多项式的节点，其中包括系数和指数。
struct Node {
    int coef;  // 系数
    int exp;   // 指数
    // 结构体的构造函数，用于初始化
    Node(int c, int e) : coef(c), exp(e) {}
};

// 函数：多项式相加
list<Node> add(const list<Node>& A, const list<Node>& B) {
    list<Node> result;  // 结果的多项式
    auto itA = A.begin(), itB = B.begin();
    // 当两个多项式都未遍历完时
    while (itA != A.end() && itB != B.end()) {
        if (itA->exp == itB->exp) {  // 指数相同
            int sum_coef = itA->coef + itB->coef;  // 系数相加
            if (sum_coef) {  // 如果系数和不为0
                result.push_back(Node(sum_coef, itA->exp));
            }
            itA++, itB++;
        }
        else if (itA->exp < itB->exp) {  // A的指数小于B
            result.push_back(*itA);
            itA++;
        }
        else {  // B的指数小于A
            result.push_back(*itB);
            itB++;
        }
    }
    // 如果A未遍历完，将剩余部分添加到结果
    while (itA != A.end()) result.push_back(*itA++);
    // 如果B未遍历完，将剩余部分添加到结果
    while (itB != B.end()) result.push_back(*itB++);
    return result;
}

// 函数：多项式相乘
list<Node> multiply(const list<Node>& A, const list<Node>& B) {
    // 使用一个大数组存储临时的乘法结果
    vector<int> temp(4100, 0); // max size is 2050 * 2

    // 对于A的每一项和B的每一项进行相乘，并更新temp数组
    for (const auto& termA : A) {
        for (const auto& termB : B) {
            temp[termA.exp + termB.exp] += termA.coef * termB.coef;
        }
    }

    list<Node> result;  // 结果的多项式
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
    // 读入第一个多项式
    for (int i = 0; i < m; i++) {
        int coef, exp;
        cin >> coef >> exp;
        poly1.push_back(Node(coef, exp));
    }
    cin >> n;
    // 读入第二个多项式
    for (int i = 0; i < n; i++) {
        int coef, exp;
        cin >> coef >> exp;
        poly2.push_back(Node(coef, exp));
    }
    cin >> op;  // 读入操作选项

    // 根据操作选项进行运算并输出
    if (op == 0 || op == 2) {  // 加法或者两者都要
        list<Node> sum = add(poly1, poly2);
        for (const Node& term : sum) {
            cout << term.coef << " " << term.exp << " ";
        }
        cout << endl;
    }
    if (op == 1 || op == 2) {  // 乘法或者两者都要
        list<Node> prod = multiply(poly1, poly2);
        for (const Node& term : prod) {
            cout << term.coef << " " << term.exp << " ";
        }
        cout << endl;
    }

    return 0;
}
