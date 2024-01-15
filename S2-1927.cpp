#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    unsigned int x;
    priority_queue<unsigned int, vector<unsigned int>, greater<unsigned int>> qu;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 0) {
            if (qu.empty()) {
                cout << "0\n";
            }
            else {
                cout << qu.top() << "\n";
                qu.pop();
            }
        }
        else {
            qu.push(x);
        }
    }

    return 0;
}