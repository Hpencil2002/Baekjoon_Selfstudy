#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

int N;
int ans;
vector<string> str;
vector<string> total;
int v[30] = { 0, };

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;

        str.push_back(tmp);
    }

    for (int i = 0; i < str.size(); i++) {
        int cnt = 0;
        memset(v, 0, sizeof(v));

        map<int, int> mp;
        string tmp = str[i];
        string t;

        for (int j = 0; j < tmp.size(); j++) {
            if (mp.count(tmp[j] - 'a') == 0) {
                mp[tmp[j] - 'a'] = 1;
                cnt += 1;
                v[tmp[j] - 'a'] = cnt;
                t += to_string(cnt);
            }
            else {
                t += to_string(v[tmp[j] - 'a']);
            }
        }

        total.push_back(t);
    }

    for (int i = 0; i < total.size(); i++) {
        for (int j = i + 1; j < total.size(); j++) {
            if (total[i] == total[j]) {
                ans += 1;
            }
        }
    }

    cout << ans;

    return 0;
}