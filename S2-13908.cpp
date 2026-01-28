#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m;
bool arr[10];
vector<char> vc;
vector<int> ans;

void dfs(int dep) {
    if (dep == n) {
        string tmp = "";

        for (int i = 0; i < 10; i++) {
            if (arr[i]) {
                bool flag = false;

                for (auto c : vc) {
                    if (c - '0' == i) {
                        flag = true;

                        break;
                    }
                }

                if (!flag) {
                    return;
                }
            }
        }

        for (auto c : vc) {
            tmp += c;
        }
        ans.push_back(stoi(tmp));

        return;
    }

    for (int i = 0; i <= 9; i++) {
        vc.push_back(i + '0');
        dfs(dep + 1);
        vc.pop_back();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;

        arr[num] = true;
    }

    dfs(0);

    cout << ans.size();

    return 0;
}