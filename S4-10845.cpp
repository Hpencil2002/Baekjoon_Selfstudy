#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    queue<int> qu;
    int N, num;
    string order;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> order;

        if (order == "push") {
            cin >> num;
            qu.push(num);
        }
        else if (order == "pop") {
            if (qu.empty()) {
                cout << "-1\n";
            }
            else {
                cout << qu.front() << "\n";
                qu.pop();
            }
        }
        else if (order == "size") {
            cout << qu.size() << "\n";
        }
        else if (order == "empty") {
            if (qu.empty()) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if (order == "front") {
            if (qu.empty()) {
                cout << "-1\n";
            }
            else {
                cout << qu.front() << "\n";
            }
        }
        else if (order == "back") {
            if (qu.empty()) {
                cout << "-1\n";
            }
            else {
                cout << qu.back() << "\n";
            }
        }
    }

    return 0;
}