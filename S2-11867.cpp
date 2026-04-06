#include <iostream>
using namespace std;

int N, M;

int main() {
    cin >> N >> M;

    if (N % 2 == 0 || M % 2 == 0) {
        cout << "A";
    }
    else {
        cout << "B";
    }

    return 0;
}