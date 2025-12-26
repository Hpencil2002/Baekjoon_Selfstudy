#include <iostream>
#include <string>
#include <vector>
using namespace std;

int A, B;
string strA, strB;
int ans;
int maxIndex;
int visit[10] = { 0, };
vector<char> vc;

void dfs(int pick, string str) {
    if (pick == 0) {
        int num = stoi(str);

        if (num != A && num < B) {
            if (maxIndex < num) {
                maxIndex = num;
                ans = num;
            }
        }
    }

    for (int i = 0; i < vc.size(); i++) {
        if (visit[i] == 0) {
            if (str.size() == 0 && vc[i] == '0') {
                continue;
            }

            visit[i] = 1;
            str.push_back(vc[i]);
            dfs(pick - 1, str);
            str.pop_back();
            visit[i] = 0;
        }
    }
}

int main() {
    cin >> A >> B;

    strA = to_string(A);
    strB = to_string(B);
    int len = (int)strA.length();

    for (int i = 0; i < len; i++) {
        vc.push_back(strA[i]);
    }

    dfs(len, "");

    if (ans == 0) {
        ans = -1;
    }

    cout << ans;

    return 0;
}