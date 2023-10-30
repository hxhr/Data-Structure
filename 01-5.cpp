#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
//一个简单的函数，把牌面值转换成数返回
int cardValue(const string& card) {
    if (card == "A") return 1;
    if (card == "2") return 2;
    if (card == "3") return 3;
    if (card == "4") return 4;
    if (card == "5") return 5;
    if (card == "6") return 6;
    if (card == "7") return 7;
    if (card == "8") return 8;
    if (card == "9") return 9;
    if (card == "10") return 10;
    if (card == "J") return 11;
    if (card == "Q") return 12;
    if (card == "K") return 13;
    return -1; // 未知牌面
}



int main() {
    int n;
    cin >> n;
    // reversed变量用于跟踪当前牌堆是否被反转。
    //也就是说，当输入Revert时，实际上没有对牌堆做任何操作，只是改变了标记方向
    bool reversed = false;
    // 使用双端队列存储牌，方便在前后进行操作。
    deque<pair<string, string>> deck;

    while (n--) {
        string cmd;
        cin >> cmd;
        if (cmd == "Append") {//添加一张牌到牌底（根据reversed判断那边是底）
            string suit, num;
            cin >> suit >> num;
            pair<string, string> card = { suit, num };
            if (reversed) {
                deck.push_front(card);
            }
            else {
                deck.push_back(card);
            }

        }
        else if (cmd == "Extract") {//提取所有指定花色的牌
            string suit;
            cin >> suit;
            vector<pair<string, string>> extractedCards;

            for (auto it = deck.begin(); it != deck.end();) {
                if (it->first == suit) {
                    extractedCards.push_back(*it);//添加
                    it = deck.erase(it);//移除
                }
                else {
                    ++it;
                }
            }
            //从begin到end都会被排序
            //第三个参数是匿名函数，告知sort的排序方式
            sort(extractedCards.begin(), extractedCards.end(),
                [](const pair<string, string>& a, const pair<string, string>& b) {
                    return cardValue(a.second) > cardValue(b.second);
                });

            if (reversed) {
                for (const auto& card : extractedCards) {
                    deck.push_back(card);
                }
            }
            else {
                for (const auto& card : extractedCards) {
                    deck.push_front(card);
                }
            }

        }
        else if (cmd == "Revert") {//直接反转标记，其余不做变动
            reversed = !reversed;

        }
        else if (cmd == "Pop") {//标记的牌顶出一张牌
            if (deck.empty()) {
                cout << "NULL" << endl;
            }
            else {
                if (reversed) {
                    cout << deck.back().first << " " << deck.back().second << endl;
                    deck.pop_back();
                }
                else {
                    cout << deck.front().first << " " << deck.front().second << endl;
                    deck.pop_front();
                }
            }
        }
    }

    if (deck.empty()) {
        cout << "NULL" << endl;
    }
    else {
        while (!deck.empty()) {
            if (reversed) {
                cout << deck.back().first << " " << deck.back().second << endl;
                deck.pop_back();
            }
            else {
                cout << deck.front().first << " " << deck.front().second << endl;
                deck.pop_front();
            }
        }
    }

    return 0;
}
