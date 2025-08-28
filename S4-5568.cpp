#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

vector<int> vc;
map<string, bool> mp;
bool visit[11];
string str;
int n, k;

void solve(int cnt) {
    if (cnt >= k) {
        if (mp[str] == false) {
            mp[str] = true;
        }
        return;
    }

    for (int i = 0; i < vc.size(); i++) {
        if (visit[i] == false) {
            visit[i] = true;

            string tmp = str;
            str += to_string(vc[i]);
            solve(cnt + 1);
            str = tmp;
            visit[i] = false;
        }
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        vc.push_back(num);
    }

    solve(0);

    cout << mp.size();

    return 0;
}