#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int n;
map<string, int> index;
pair<int, string> ans[100];

int main() {
    cin >> n;

    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;

        index.insert({ str, i });
        ans[i].second = str;
    }

    while (cin >> str) {
        ans[index[str]].first -= 1;
    }

    sort(ans, ans + n);

    for (int i = 0; i < n; i++) {
        cout << ans[i].second << ' ' << -ans[i].first << "\n";
    }

    return 0;
}