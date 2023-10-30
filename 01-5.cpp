#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
//һ���򵥵ĺ�����������ֵת����������
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
    return -1; // δ֪����
}



int main() {
    int n;
    cin >> n;
    // reversed�������ڸ��ٵ�ǰ�ƶ��Ƿ񱻷�ת��
    //Ҳ����˵��������Revertʱ��ʵ����û�ж��ƶ����κβ�����ֻ�Ǹı��˱�Ƿ���
    bool reversed = false;
    // ʹ��˫�˶��д洢�ƣ�������ǰ����в�����
    deque<pair<string, string>> deck;

    while (n--) {
        string cmd;
        cin >> cmd;
        if (cmd == "Append") {//���һ���Ƶ��Ƶף�����reversed�ж��Ǳ��ǵף�
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
        else if (cmd == "Extract") {//��ȡ����ָ����ɫ����
            string suit;
            cin >> suit;
            vector<pair<string, string>> extractedCards;

            for (auto it = deck.begin(); it != deck.end();) {
                if (it->first == suit) {
                    extractedCards.push_back(*it);//���
                    it = deck.erase(it);//�Ƴ�
                }
                else {
                    ++it;
                }
            }
            //��begin��end���ᱻ����
            //������������������������֪sort������ʽ
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
        else if (cmd == "Revert") {//ֱ�ӷ�ת��ǣ����಻���䶯
            reversed = !reversed;

        }
        else if (cmd == "Pop") {//��ǵ��ƶ���һ����
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
