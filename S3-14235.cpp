#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pqu;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (a != 0) {
            for (int j = 0; j < a; j++) {
                int num;
                cin >> num;
                pqu.push(num);
            }
        }
        else {
            if (pqu.empty()) {
                cout << "-1\n";
            }
            else {
                cout << pqu.top() << "\n";
                pqu.pop();
            }
        }
    }

    return 0;
}