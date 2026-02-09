#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<vector<vector<int>>> vc(8);
int ans = 1e9;

void rotate(vector<vector<int>>& ori, vector<vector<int>>& trans) {
    trans = vector<vector<int>>(N);

    int l = N - 1;
    for (int i = l; i >= 0; i--) {
        for (int j = i; j < N; j++) {
            trans[l - i].push_back(ori[j][i]);
        }
    }
}

void opposite(vector<vector<int>>& ori) {
    for (int i = 0; i < N; i++) {
        int l = 0;
        int r = i;

        while (l < r) {
            swap(ori[i][l], ori[i][r]);
            l += 1;
            r -= 1;
        }
    }
}

int check(vector<vector<int>>& v1, vector<vector<int>>& v2) {
    int res = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (v1[i][j] != v2[i][j]) {
                res += 1;
            }
        }
    }

    return res;
}

int main() {
    cin >> N;
    for (int i = 0; i < 2; i++) {
        vc[i] = vector<vector<int>>(N);

        for (int j = 0; j < N; j++) {
            for (int k = 0; k <= j; k++) {
                int t;
                cin >> t;

                vc[i][j].push_back(t);
            }
        }
    }

    rotate(vc[0], vc[2]);
    rotate(vc[0], vc[3]);
    opposite(vc[3]);
    ans = min(ans, check(vc[1], vc[2]));
    ans = min(ans, check(vc[1], vc[3]));

    rotate(vc[2], vc[4]);
    rotate(vc[2], vc[5]);
    opposite(vc[5]);
    ans = min(ans, check(vc[1], vc[4]));
    ans = min(ans, check(vc[1], vc[5]));

    rotate(vc[4], vc[6]);
    rotate(vc[4], vc[7]);
    opposite(vc[7]);
    ans = min(ans, check(vc[1], vc[6]));
    ans = min(ans, check(vc[1], vc[7]));

    cout << ans;

    return 0;
}