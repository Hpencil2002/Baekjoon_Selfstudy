#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int ans = INT_MAX;
int s, e;

void comp(vector<string> a, vector<string> b, int x, int y) {
    int cnt = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            if (a[i][j] != b[i][j]) {
                cnt += 1;
            }
        }
    }

    if (ans > cnt) {
        ans = cnt;
        s = x + 1;
        e = y + 1;
    }
}

int main() {
    int N;
    cin >> N;

    vector<vector<string>> vc;
    vc.resize(N, vector<string>());

    string tmp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> tmp;
            vc[i].push_back(tmp);
        }
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            comp(vc[i], vc[j], i, j);
        }
    }

    cout << s << ' ' << e;

    return 0;
}