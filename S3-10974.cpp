#include <iostream>
using namespace std;

int N;
int num[9];
int visited[9];

void solve(int index) {
    if (index == N) {
        for (int i = 0; i < N; i++) {
            cout << num[i] << ' ';
        }

        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            num[index] = i + 1;
            solve(index + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> N;

    solve(0);

    return 0;
}