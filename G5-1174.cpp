#include <iostream>
#include <cstring>
using namespace std;

int N;
long long arr[1023];

int main() {
    cin >> N;
    if (N > 1023) {
        cout << -1;

        return 0;
    }

    int index = 0;
    for (int i = 0; i <= 9; i++) {
        arr[index++] = i;
    }

    for (int i = 1; i < 1022; i++) {
        long long tmp = arr[i];

        for (int j = 0; j <= 9; j++) {
            if (tmp % 10 > j) {
                arr[index++] = tmp * 10 + j;
            }
        }
    }

    cout << arr[N - 1];

    return 0;
}