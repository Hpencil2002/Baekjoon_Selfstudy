#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int milk[1000];
    for (int i = 0; i < N; i++) {
        cin >> milk[i];
    }

    int ans = 0;
    int check = 0;
    for (int i = 0; i < N; i++) {
        if (milk[i] == 0 && check == 0) {
            ans += 1;
            check = 1;
        }
        if (milk[i] == 1 && check == 1) {
            ans += 1;
            check = 2;
        }
        if (milk[i] == 2 && check == 2) {
            ans += 1;
            check = 0;
        }
    }

    cout << ans;

    return 0;
}