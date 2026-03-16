#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<string> ans;

void solve(int target, int sum, int sign, int prev, int index, string expr) {
    if (index == target) {
        sum += (prev * sign);

        if (sum == 0) {
            ans.push_back(expr);
        }

        return;
    }
    else {
        solve(target, sum + (prev * sign), 1, index + 1, index + 1, expr + '+' + to_string(index + 1));
        solve(target, sum + (prev * sign), -1, index + 1, index + 1, expr + '-' + to_string(index + 1));
        solve(target, sum, sign, prev * 10 + (index + 1), index + 1, expr + ' ' + to_string(index + 1));
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> N;

        solve(N, 0, 1, 1, 1, "1");

        sort(ans.begin(), ans.end());

        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << "\n";
        }
        cout << "\n";

        ans.clear();
    }

    return 0;
}