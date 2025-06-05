#include <iostream>
using namespace std;

int main() {
    int num[5];
    int ans = 0;

    for (int i = 0; i < 5; i++) {
        cin >> num[i];
        ans += num[i] * num[i];
    }

    cout << ans % 10;

    return 0;
}