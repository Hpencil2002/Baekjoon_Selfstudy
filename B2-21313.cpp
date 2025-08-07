#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int tmp = N % 2 ? N - 1 : N;
    for (int i = 0; i < tmp; i++) {
        if (i % 2) {
            cout << "2 ";
        }
        else {
            cout << "1 ";
        }
    }

    if (N % 2) {
        cout << "3";
    }

    return 0;
}