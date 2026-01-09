#include <iostream>
#include <stack>
using namespace std;

int N;
int ans;
char c;
stack<char> lr;
stack<char> sk;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> c;

        if (c == 'L') {
            lr.push(c);
        }
        else if (c == 'R') {
            if (!lr.empty()) {
                ans += 1;
                lr.pop();
            }
            else {
                break;
            }
        }
        else if (c == 'S') {
            sk.push(c);
        }
        else if (c == 'K') {
            if (!sk.empty()) {
                ans += 1;
                sk.pop();
            }
            else {
                break;
            }
        }
        else {
            ans += 1;
        }
    }

    cout << ans;

    return 0;
}