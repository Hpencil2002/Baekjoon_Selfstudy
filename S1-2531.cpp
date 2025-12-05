#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, d, k, c;
int flag, cnt, coupon, maxIndex;
int arr[300001];
int check[3001];
vector<int> vc;

int main() {
    cin >> N >> d >> k >> c;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        flag = 0;
        coupon = 1;

        for (int j = i; j < i + k; j++) {
            if (check[arr[j % N]] == 1) {
                flag += 1;
            }
            else {
                check[arr[j % N]] = 1;
            }

            if (arr[j % N] == c) {
                coupon = 0;
            }
        }

        maxIndex = max(maxIndex, k - flag + coupon);

        memset(check, 0, sizeof(check));
    }

    cout << maxIndex;

    return 0;
}