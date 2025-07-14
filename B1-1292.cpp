#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int arr[1001];
    int cnt = 0;
    for (int i = 1; cnt < 1000; i++) {
        for (int j = 0; j < i; j++) {
            arr[cnt++] = i;

            if (cnt == 1000) {
                break;
            }
        }
    }

    int ans = 0;
    for (int i = A - 1; i <= B - 1; i++) {
        ans += arr[i];
    }
    cout << ans;

    return 0;
}