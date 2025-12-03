#include <iostream>
#include <string>
using namespace std;

int N;
int arr[70][70];

void dfs(int x, int y, int size) {
    if (size == 1) {
        cout << arr[x][y];

        return;
    }

    bool onlyZero = true;
    bool onlyOne = true;
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (arr[i][j] == 0) {
                onlyOne = false;
            }
            if (arr[i][j] == 1) {
                onlyZero = false;
            }
        }
    }

    if (onlyZero) {
        cout << 0;

        return;
    }
    if (onlyOne) {
        cout << 1;

        return;
    }

    cout << "(";
    dfs(x, y, size / 2);
    dfs(x, y + size / 2, size / 2);
    dfs(x + size / 2, y, size / 2);
    dfs(x + size / 2, y + size / 2, size / 2);
    cout << ")";
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            arr[i][j] = str[j] - '0';
        }
    }

    dfs(0, 0, N);

    return 0;
}