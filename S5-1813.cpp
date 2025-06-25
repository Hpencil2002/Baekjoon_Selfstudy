#include <iostream>
using namespace std;

int main() {
    int N;
    int arr[51] { 0, };

    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        arr[tmp] += 1;
    }

    for (int i = 50; i >= 0; i--) {
        if (arr[i] == i) {
            cout << i;
            return 0;
        }
    }

    cout << -1;

    return 0;
}