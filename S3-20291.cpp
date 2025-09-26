#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> vc;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        str.erase(0, str.find('.') + 1);
        vc.push_back(str);
    }

    sort(vc.begin(), vc.end());

    string tmp = vc[0];
    int cnt = 0;
    vector<pair<string, int>> ans;
    for (int i = 0; i < vc.size(); i++) {
        if (tmp == vc[i]) {
            cnt += 1;
        }
        else {
            ans.push_back({tmp, cnt});
            tmp = vc[i];
            cnt = 1;
        }
    }
    ans.push_back({tmp, cnt});

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << ' ' << ans[i].second << "\n";
    }

    return 0;
}