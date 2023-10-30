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


//开始第一遍92
////代码在计算起始位置时有一点小瑕疵。即使maxLen保持不变，startPos的值也可能需要更新
// ，因为它应该指向第一个找到的最长子串，而不是最后一个。
//
//为了解决这个问题，应该在更新maxLen时只更新startPos。

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