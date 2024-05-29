#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>> qu;
    int N;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a == 0) {
            if (qu.empty()) { 
                cout << 0 << "\n";
            }
            else {
                cout << qu.top() << "\n";
                qu.pop();
            }
        }
        else {
            qu.push(a);
        }
    }

    return 0;
}