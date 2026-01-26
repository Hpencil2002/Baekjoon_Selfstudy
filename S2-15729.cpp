#include <iostream>
using namespace std;

int N;
int arr[1000001];
int ans;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        if (arr[i] == 1) {
            ans += 1;

            if (arr[i + 1] == 1) {
                arr[i + 1] = 0;
            }
            else {
                arr[i + 1] = 1;
            }

            if (arr[i + 2] == 1) {
                arr[i + 2] = 0;
            }
            else {
                arr[i + 2] = 1;
            }
        }
    }

    cout << ans;

    return 0;
}