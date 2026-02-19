#include <iostream>
#include <algorithm>
using namespace std;

struct LINE {
    int left;
    int right;
};

int N;
int dp[110];
LINE line[110];
int correct;

bool cmp(LINE a, LINE b) {
    return a.left < b.left;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> line[i].left >> line[i].right;
    }

    sort(line + 1, line + N + 1, cmp);

    for (int i = 1; i <= N; i++) {
        dp[i] = 1;

        for (int j = 1; j < i; j++) {
            if (line[i].right > line[j].right) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        correct = max(correct, dp[i]);
    }

    cout << N - correct;

    return 0;
}