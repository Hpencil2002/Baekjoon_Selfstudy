#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
int ans = 99999999;
bool team[20];
int score[20][20];

void solve(int index, int cnt) {
    vector<int> start;
    vector<int> link;
    int start_score = 0;
    int link_score = 0;

    if (cnt == (N / 2)) {
        for (int i = 0; i < N; i++) {
            if (team[i]) {
                start.push_back(i);
            }
            else {
                link.push_back(i);
            }
        }

        for (int i = 0; i < (N / 2); i++) {
            for (int j = 0; j < (N / 2); j++) {
                start_score += score[start[i]][start[j]];
                link_score += score[link[i]][link[j]];
            }
        }

        if (abs(start_score - link_score) < ans) {
            ans = abs(start_score - link_score);
        }

        return;
    }

    for (int i = index; i < N; i++) {
        if (team[i]) {
            continue;
        }
        else {
            team[i] = true;
            solve(i, cnt + 1);
            team[i] = false;
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> score[i][j];
        }
    }

    solve(0, 0);

    cout << ans;

    return 0;
}