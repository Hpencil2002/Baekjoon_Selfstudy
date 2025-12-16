#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N;
int ans;
map<string, int> mp;
vector<int> vc;

int main() {
    cin >> N;

    vc.resize(N, 0);
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        mp[str] = i;
    }
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        vc[i] = mp[str];
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (vc[i] > vc[j]) {
                ans += 1;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}