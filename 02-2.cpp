//#include <iostream>
//#include <stack>
//#include <string>
//#include <sstream>
//using namespace std;
//
//
////第一遍写的时候。对于not and or是并列判断，这会让在涉及到例如（!V&V）时出现错误，会先算V&V，这是不对的。
//bool evaluate(string exp) {
//    stack<bool> operands;//存储V F
//    stack<char> operators;//存储其他操作符
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


//第二遍修改后过了80%，就差在！！一旦连续，并且&！！这种，就差一个等号，我在代码中标注。排查好久
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
            operands.push(val2 && val1);  // 注意这里的顺序
        }
        else {
            operands.push(val2 || val1);  // 注意这里的顺序
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
        else {//下一行有等号就过不了。。
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
