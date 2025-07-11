#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<char>> vc(N);
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < str.size(); j++) {
            vc[i].push_back(str[j]);
        }
    }

    int ans = 0;

    for (int i = 0; i < N; i++) {
        char row = vc[i][0];
        ans += 1;

        if (i > 0 && row == '|' && row == vc[i - 1][0]) {
            ans -= 1;
        }

        for (int j = 1; j < M; j++) {
            if (row != vc[i][j] || (row == vc[i][j] && row == '|')) {
                ans += 1;
                row = vc[i][j];
            }

            if (i > 0 && vc[i][j] == '|' && vc[i][j] == vc[i - 1][j]) {
                ans -= 1;
            }
        }
    }

    cout << ans;

    return 0;
}