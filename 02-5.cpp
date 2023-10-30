#include <iostream>
#include <deque>
#include <string>
using namespace std;


//
//为了实现GetMax()操作的高效，我们可以使用一个双端队列（deque）来辅助我们存储队列中的最大值。
//
//具体方法如下：
//
//使用两个队列，一个队列q用于正常的入队和出队操作，另一个队列max_deque用于存储队列中的最大值。
//当一个新元素入队时，将其添加到q队列的尾部。同时，从max_deque的尾部开始，删除所有小于这个元素的元素，然后将新元素添加到max_deque的尾部。这确保了max_deque的头部总是q中当前最大的元素。
//当一个元素出队时，检查这个元素是否是max_deque的头部，如果是的话也从max_deque中删除它。
//GetMax()只需要返回max_deque的头部元素。

//这种方法可以确保GetMax()操作的时间复杂度为O(1)。而且，虽然每次入队和出队操作可能涉及多次push_back()和pop_front()，
//但由于每个元素只会被push_back()和pop_front()一次，所以这些操作的摊还时间复杂度仍然是O(1)。

int main() {
    int n;
    cin >> n;

    deque<int> q;  // 主队列
    deque<int> max_deque;  // 辅助队列，存储最大值

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
