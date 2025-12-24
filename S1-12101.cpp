#include <iostream>
#include <string>
#include <map>
using namespace std;

int n, k;
int arr[3] = { 1, 2, 3 };
map<string, int> mp;

void dfs(string str, int sum) {
    for (int i = 0; i < 3; i++) {
        sum += arr[i];

        if (sum > n) {
            continue;
        }
        else if (sum == n) {
            mp[str + to_string(arr[i])] += 1;
        }
        else {
            dfs(str + to_string(arr[i]) + "+", sum);
        }

        sum -= arr[i];
    }
}

int main() {
    cin >> n >> k;

    dfs("", 0);

    if (k > mp.size()) {
        cout << "-1\n";

        return 0;
    }

    int cnt = 0;
    for (auto it : mp) {
        cnt += 1;

        if (cnt == k) {
            cout << it.first << "\n";
        }
    }

    return 0;
}