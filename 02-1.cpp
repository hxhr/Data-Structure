#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string in, string out) {
    stack<char> station;
    int j = 0;
    for (int i = 0; i < (int)in.size(); ++i) {
        station.push(in[i]);
        while (!station.empty() && j < (int)out.size() && station.top() == out[j]) {
            station.pop();
            ++j;
        }
    }
    return station.empty() && j == out.size();
}

int main() {
    string in;
    cin >> in;
    string out;
    while (cin >> out) {
        if (isValid(in, out)) {
            cout << "yes" << endl;
        }
        else {

            cout << "no" << endl;
        }
    }
    return 0;
}
