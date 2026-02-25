#include <iostream>
using namespace std;

int N;

bool check(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

void dfs(int num, int len) {
    if (len == N) {
        cout << num << "\n";

        return;
    }

    for (int i = 1; i <= 9; i++) {
        if (check(num * 10 + i)) {
            dfs(num * 10 + i, len + 1);
        }
    }

    return;
}

int main() {
    cin >> N;

    dfs(2, 1);
    dfs(3, 1);
    dfs(5, 1);
    dfs(7, 1);

    return 0;
}