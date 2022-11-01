#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    deque<int> dq;
    string order;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> order;

        if (order == "push_front") {
            int num;
            cin >> num;
            dq.push_front(num);
        }
        else if (order == "push_back") {
            int num;
            cin >> num;
            dq.push_back(num);
        }
        else if (order == "pop_front") {
            if (dq.empty()) {
                cout << "-1\n";
            }
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        else if (order == "pop_back") {
            if (dq.empty()) {
                cout << "-1\n";
            }
            else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        else if (order == "size") {
            cout << dq.size() << "\n";
        }
        else if (order == "empty") {
            cout << (int)dq.empty() << "\n";
        }
        else if (order == "front") {
            if (dq.empty()) {
                cout << "-1\n";
            }
            else {
                cout << dq.front() << "\n";
            }
        }
        else if (order == "back") {
            if (dq.empty()) {
                cout << "-1\n";
            }
            else {
                cout << dq.back() << "\n";
            }
        }
    }

    return 0;
}