#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    bool check = true;
    while (M--) {
        int k;
        cin >> k;

        int old = N + 1;
        for (int i = 0; i < k; i++) {
            int num;
            cin >> num;

            if (num > old) {
                check = false;
            }

            old = num;
        }
    }

    if (check) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    return 0;
}