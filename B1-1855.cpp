#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int N;
    string str;
    cin >> N >> str;

    int c = 0;
    int rem;
    int cycle;
    bool flag = false;
    char map[20][200];

    memset(map, ' ', sizeof(map));
    cycle = (str.length() + N - 1) / N;

    for (int i = 0; i < cycle; i++) {
        if (!flag) {
            for (int j = 0; j < N; j++) {
                map[i][j] = str[c++];
            }
        }
        else {
            for (int j = N - 1; j >= 0; j--) {
                map[i][j] = str[c++];
            }
        }

        flag = !flag;
    }

    string ans = "";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < cycle; j++) {
            ans += map[j][i];
        }
    }

    cout << ans;

    return 0;
}