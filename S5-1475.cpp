#include <iostream>
using namespace std;

int main() {
    int arr[10] = { 0, };
    int N;

    cin >> N;
    while (N > 0) {
        if (N % 10 == 6 || N % 10 == 9) {
            if (arr[6] == arr[9]) {
                arr[6] += 1;
            }
            else {
                arr[9] += 1;
            }
        }
        else {
            arr[N % 10] += 1;
        }

        N /= 10;
    }

    int max = arr[0];
    for (int i = 1; i < 10; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    cout << max;

    return 0;
}