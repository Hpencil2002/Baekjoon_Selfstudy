#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, n;
    cin >> T;

    for (int i = 0; i < T; i++) {
        deque<int> dq;
        string p, input;
        bool err = false;

        cin >> p;
        cin >> n;
        cin >> input;

        string tmp = "";
        if (n != 0) {
            for (int j = 0; j < input.length(); j++) {
                if(input[j] == '[' || input[j] == ']' || input[j] == ',') {
                    if (input[j] != '[') {
                        dq.push_back(stoi(tmp));
                    }
                    tmp = "";
                    continue;
                }
                tmp += input[j];
            }
        }

        int rev = 1;
        for (int j = 0; j < p.length(); j++) {
            if (p[j] == 'R') {
                rev *= -1;
            }
            else {
                if (dq.empty()) {
                    cout << "error\n";
                    err = true;
                    break;
                }

                if (rev == 1) {
                    dq.pop_front();
                }
                else {
                    dq.pop_back();
                }
            }
        }

        if (!err) {
            cout << "[";
            if (rev == 1) {
                while (!dq.empty()) {
                    if (dq.size() != 1) {
                        cout << dq.front() << ",";
                    }
                    else {
                        cout << dq.front();
                    }
                    dq.pop_front();
                }
            }
            else {
                while (!dq.empty()) {
                    if (dq.size() != 1) {
                        cout << dq.back() << ",";
                    }
                    else {
                        cout << dq.back();
                    }
                    dq.pop_back();
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}