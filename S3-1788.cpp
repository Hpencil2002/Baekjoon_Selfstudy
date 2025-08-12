#include <iostream>
using namespace std;

long long DP(int num) {
    long long arr[1000001];

    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= num; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000000;
    }

    return arr[num] % 1000000000;
}

int main() {
    int n;
    cin >> n;

    int flag = 1;
    if (n < 0) {
        n *= -1;
        if (n % 2 == 0) {
            flag = -1;
        }
    }

    if (n == 0) {
        flag = 0;
    }

    cout << flag << "\n" << DP(n);

    return 0;
}