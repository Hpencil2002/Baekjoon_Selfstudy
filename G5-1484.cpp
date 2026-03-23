#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int G;
vector<pair<int, int>> Div;
vector<int> ans;

vector<pair<int, int>> getDiv(int n) {
    vector<pair<int, int>> vc;

    for (int i = 1; i * i < n; i++) {
        if (n % i == 0) {
            vc.push_back({ n / i, i });
        }
    }

    return vc;
}

int main() {
    cin >> G;

    Div = getDiv(G);

    for (int i = 0; i < Div.size(); i++) {
        int sum = Div[i].first + Div[i].second;

        if (sum % 2 == 0) {
            ans.push_back(sum / 2);
        }
    }

    sort(ans.begin(), ans.end());

    if (ans.size() == 0) {
        cout << -1;
    }
    else {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << "\n";
        }
    }

    return 0;
}