#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int ans;
vector<string> vc;
vector<bool> check;

int main() {
    cin >> N;

    vc = vector<string>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    sort(vc.begin(), vc.end());

    check = vector<bool>(N, true);
    for (int i = 0; i < vc.size(); i++) {
        for (int j = i + 1; j < vc.size(); j++) {
            if (vc[j].substr(0, vc[i].size()) == vc[i]) {
                check[i] = false;
                break;
            }
        }
    }

    for (int i = 0; i < check.size(); i++) {
        if (check[i]) {
            ans += 1;
        }
    }

    cout << ans;

    return 0;
}