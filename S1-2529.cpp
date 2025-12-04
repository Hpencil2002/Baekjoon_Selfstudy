#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int k;
char arr[10];
int pick[10];
bool used[10];
string maxAns = "0000000000";
string minAns = "9999999999";

string pickToString() {
    string res = "";

    for (int i = 0; i <= k; i++) {
        res += pick[i] + '0';
    }

    return res;
}

void getAns() {
    string ans = pickToString();
    maxAns = max(maxAns, ans);
    minAns = min(minAns, ans);
}

void solve(int index) {
    if (index > k) {
        getAns();

        return;
    }

    for (int i = 0; i < 10; i++) {
        if (used[i]) {
            continue;
        }

        if (arr[index - 1] == '<' && pick[index - 1] > i) {
            continue;
        }
        else if (arr[index - 1] == '>' && pick[index - 1] < i) {
            continue;
        }

        used[i] = true;
        pick[index] = i;
        solve(index + 1);
        used[i] = false;
    }
}

int main() {
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }

    solve(0);

    cout << maxAns << "\n" << minAns;

    return 0;
}