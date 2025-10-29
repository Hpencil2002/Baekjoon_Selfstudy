#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int blind[5] = { 0, };
char mp[510][510];

int main() {
    int M, N;
    cin >> M >> N;

    for (int i = 0; i < M * 5 + 1; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < str.size(); j++) {
            mp[i][j] = str[j];
        }
    }

    for (int i = 1; i < M * 5 + 1; i += 5) {
        for (int j = 1; j < N * 5 + 1; j += 5) {
            if (mp[i][j] == '.') {
                blind[0] += 1;
            }
            else if (mp[i + 1][j] == '.') {
                blind[1] += 1;
            }
            else if (mp[i + 2][j] == '.') {
                blind[2] += 1;
            }
            else if (mp[i + 3][j] == '.') {
                blind[3] += 1;
            }
            else {
                blind[4] += 1;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        cout << blind[i] << ' ';
    }

    return 0;
}