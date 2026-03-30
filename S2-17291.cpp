#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[21];
int ans;

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        if (i == 1) {
            arr[i] = 1;
        }
        else if (i == 2) {
            arr[i] = 1;
        }
        else if (i == 3) {
            arr[i] = 2;
        }
        else {
            int sum = 0;
            for (int j = 1; j <= i; j++) {
                sum += arr[j];
            }
            arr[i] = sum;

            if (i % 2 == 0) {
                int tmp1 = i - 3;
                int tmp2 = i - 4;

                if (tmp1 >= 0) {
                    arr[tmp1] = 0;
                }
                if (tmp2 >= 0) {
                    arr[tmp2] = 0;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        ans += arr[i];
    }

    cout << ans;

    return 0;
}