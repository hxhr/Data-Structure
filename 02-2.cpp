//#include <iostream>
//#include <stack>
//#include <string>
//#include <sstream>
//using namespace std;
//
//
////��һ��д��ʱ�򡣶���not and or�ǲ����жϣ���������漰�����磨!V&V��ʱ���ִ��󣬻�����V&V�����ǲ��Եġ�
//bool evaluate(string exp) {
//    stack<bool> operands;//�洢V F
//    stack<char> operators;//�洢����������
//
//    for (char ch : exp) {
//        if (ch == 'V') {
//            operands.push(true);
//        }
//        else if (ch == 'F') {
//            operands.push(false);
//        }
//        else if (ch == '&' || ch == '|' || ch == '!' || ch == '(') {
//            operators.push(ch);
//        }
//        else if (ch == ')') {
//            while (operators.top() != '(') {
//                char op = operators.top();
//                operators.pop();
//
//                if (op == '!') {
//                    bool val = operands.top();
//                    operands.pop();
//                    operands.push(!val);
//                }
//                else {
//                    bool val1 = operands.top();
//                    operands.pop();
//                    bool val2 = operands.top();
//                    operands.pop();
//                    if (op == '&') {
//                        operands.push(val1 && val2);
//                    }
//                    else {
//                        operands.push(val1 || val2);
//                    }
//                }
//            }
//            operators.pop();  // Remove '('
//        }
//    }
//
//    while (!operators.empty()) {
//        char op = operators.top();
//        operators.pop();
//
//        if (op == '!') {
//            bool val = operands.top();
//            operands.pop();
//            operands.push(!val);
//        }
//        else {
//            bool val1 = operands.top();
//            operands.pop();
//            bool val2 = operands.top();
//            operands.pop();
//            if (op == '&') {
//                operands.push(val1 && val2);
//            }
//            else {
//                operands.push(val1 || val2);
//            }
//        }
//    }
//
//    return operands.top();
//}
//
//int main() {
//    string line;
//    int expressionNumber = 0;
//
//    while (getline(cin, line)) {
//        expressionNumber++;
//        bool result = evaluate(line);
//        cout << "Expression " << expressionNumber << ": " << (result ? "V" : "F") << endl;
//    }
//
//}


//�ڶ����޸ĺ����80%���Ͳ��ڣ���һ������������&�������֣��Ͳ�һ���Ⱥţ����ڴ����б�ע���Ų�þ�
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

int getPriority(char op) {
    if (op == '!') return 3;
    if (op == '&') return 2;
    if (op == '|') return 1;
    return 0;
}

bool applyOperator(char op, stack<bool>& operands) {
    if (op == '!') {
        if (operands.empty()) return false;
        bool val = operands.top();
        operands.pop();
        operands.push(!val);
    }
    else {
        if (operands.size() < 2) return false;
        bool val1 = operands.top();
        operands.pop();
        bool val2 = operands.top();
        operands.pop();
        if (op == '&') {
            operands.push(val2 && val1);  // ע�������˳��
        }
        else {
            operands.push(val2 || val1);  // ע�������˳��
        }
    }
    return true;
}

bool evaluate(string exp) {
    stack<bool> operands;
    stack<char> operators;

    for (char ch : exp) {
        if (ch == ' ') continue;

        if (ch == 'V') {
            operands.push(true);
        }
        else if (ch == 'F') {          operands.push(false);
        }
        else if (ch == '(') {
            operators.push(ch);
        }
        else if (ch == ')') {
            while (operators.top() != '(') {
                if (!applyOperator(operators.top(), operands)) return false;
                operators.pop();
            }
            operators.pop();  // Remove '('
        }
        else {//��һ���еȺž͹����ˡ���
            while (!operators.empty() && getPriority(ch) < getPriority(operators.top())) {
                if (!applyOperator(operators.top(), operands)) return false;
                operators.pop();
            }
            operators.push(ch);
        }
    }

    while (!operators.empty()) {
        if (!applyOperator(operators.top(), operands)) return false;
        operators.pop();
    }

    return operands.top();
}

int main() {
    string line;
    int expressionNumber = 0;

    while (getline(cin, line)) {
        expressionNumber++;
        bool result = evaluate(line);
        cout << "Expression " << expressionNumber << ": " << (result ? "V" : "F") << endl;
    }

    return 0;
}
