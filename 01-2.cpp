#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ����һ��ѧ���ṹ�壬����ѧ�ź�����
struct Student {
    string id;
    string name;
};

int main() {
    int n;  // ѧ������
    cin >> n;

    // ����һ������Ϊ n ��ѧ������
    vector<Student> students(n);

    // ���� n ��ѧ������Ϣ
    for (int i = 0; i < n; i++) {
        cin >> students[i].id >> students[i].name;
    }

    string operation;  // �����ַ����������ж���Ҫִ�еĲ���
    while (true) {
        cin >> operation;

        if (operation == "insert") {
            int pos;  // �����λ��
            string id, name;
            cin >> pos >> id >> name;

            // �жϲ���λ���Ƿ���Ч
            if (pos >= 1 && static_cast<size_t>(pos) <= students.size() + 1) {
                Student newStudent = { id, name };
                students.insert(students.begin() + pos - 1, newStudent);  // ����ѧ��
                cout << "0" << endl;  // ��� 0 ��ʾ����ɹ�
            }
            else {
                cout << "-1" << endl;  // ��� -1 ��ʾ����ʧ��
            }

        }
        else if (operation == "remove") {
            int pos;  // ɾ����λ��
            cin >> pos;

            // �ж�ɾ��λ���Ƿ���Ч
            if (pos >= 1 && static_cast<size_t>(pos) <= students.size()) {
                students.erase(students.begin() + pos - 1);  // ɾ��ѧ��
                cout << "0" << endl;  // ��� 0 ��ʾɾ���ɹ�
            }
            else {
                cout << "-1" << endl;  // ��� -1 ��ʾɾ��ʧ��
            }

        }
        else if (operation == "check") {
            string type, value;  // ��ѯ�����ͣ�������ѧ�ţ��Ͳ�ѯ��ֵ
            cin >> type >> value;
            bool found = false;

            // ����ѧ���б����ƥ���ѧ��
            for (size_t i = 0; i < students.size(); i++) {
                if ((type == "name" && students[i].name == value) ||
                    (type == "no" && students[i].id == value)) {
                    cout << i + 1 << " " << students[i].id << " " << students[i].name << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "-1" << endl;  // ���δ�ҵ������ -1
            }

        }
        else if (operation == "end") {
            cout << students.size() << endl;  // �����ǰѧ������
            break;  // ��������
        }
    }

    return 0;
}
