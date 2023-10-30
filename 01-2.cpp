#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 定义一个学生结构体，包含学号和姓名
struct Student {
    string id;
    string name;
};

int main() {
    int n;  // 学生数量
    cin >> n;

    // 创建一个容量为 n 的学生向量
    vector<Student> students(n);

    // 输入 n 个学生的信息
    for (int i = 0; i < n; i++) {
        cin >> students[i].id >> students[i].name;
    }

    string operation;  // 操作字符串，用于判断所要执行的操作
    while (true) {
        cin >> operation;

        if (operation == "insert") {
            int pos;  // 插入的位置
            string id, name;
            cin >> pos >> id >> name;

            // 判断插入位置是否有效
            if (pos >= 1 && static_cast<size_t>(pos) <= students.size() + 1) {
                Student newStudent = { id, name };
                students.insert(students.begin() + pos - 1, newStudent);  // 插入学生
                cout << "0" << endl;  // 输出 0 表示插入成功
            }
            else {
                cout << "-1" << endl;  // 输出 -1 表示插入失败
            }

        }
        else if (operation == "remove") {
            int pos;  // 删除的位置
            cin >> pos;

            // 判断删除位置是否有效
            if (pos >= 1 && static_cast<size_t>(pos) <= students.size()) {
                students.erase(students.begin() + pos - 1);  // 删除学生
                cout << "0" << endl;  // 输出 0 表示删除成功
            }
            else {
                cout << "-1" << endl;  // 输出 -1 表示删除失败
            }

        }
        else if (operation == "check") {
            string type, value;  // 查询的类型（姓名或学号）和查询的值
            cin >> type >> value;
            bool found = false;

            // 遍历学生列表查找匹配的学生
            for (size_t i = 0; i < students.size(); i++) {
                if ((type == "name" && students[i].name == value) ||
                    (type == "no" && students[i].id == value)) {
                    cout << i + 1 << " " << students[i].id << " " << students[i].name << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "-1" << endl;  // 如果未找到，输出 -1
            }

        }
        else if (operation == "end") {
            cout << students.size() << endl;  // 输出当前学生数量
            break;  // 结束程序
        }
    }

    return 0;
}
