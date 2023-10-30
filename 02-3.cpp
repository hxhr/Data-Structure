#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<int> st;
    int maxlen = 0;
    int startpos = 0;
    int lastinvalidpos = -1;
    if ((int)s.size() == 0) {
        lastinvalidpos = 0;
    }
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
        }
        else {
            if (!st.empty()) {
                st.pop();
                if (st.empty()) {
                    maxlen = max(maxlen, i - lastinvalidpos);
                    startpos = (maxlen == i - lastinvalidpos) ? lastinvalidpos + 1 : startpos;
                }
                else {
                    maxlen = max(maxlen, i - st.top());
                    startpos = (maxlen == i - st.top()) ? st.top() + 1 : startpos;
                }
            }
            else {
                lastinvalidpos = i;
            }
        }
    }

    cout << maxlen << " " << startpos << endl;

    return 0;
}


//��ʼ��һ��92
////�����ڼ�����ʼλ��ʱ��һ��С覴á���ʹmaxLen���ֲ��䣬startPos��ֵҲ������Ҫ����
// ����Ϊ��Ӧ��ָ���һ���ҵ�����Ӵ������������һ����
//
//Ϊ�˽��������⣬Ӧ���ڸ���maxLenʱֻ����startPos��

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<int> st;
    int maxLen = 0;
    int startPos = 0;
    int lastInvalidPos = -1;

    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
        }
        else {
            if (!st.empty()) {
                st.pop();
                if (st.empty()) {
                    if (i - lastInvalidPos > maxLen) {
                        maxLen = i - lastInvalidPos;
                        startPos = lastInvalidPos + 1;
                    }
                }
                else {
                    if (i - st.top() > maxLen) {
                        maxLen = i - st.top();
                        startPos = st.top() + 1;
                    }
                }
            }
            else {
                lastInvalidPos = i;
            }
        }
    }

    cout << maxLen << " " << startPos << endl;

    return 0;
}


int main()
{
	cout << (int)'(' << (int)')' << (int)'{' << (int)'}' << (int)'[' << (int)']' << endl;
}