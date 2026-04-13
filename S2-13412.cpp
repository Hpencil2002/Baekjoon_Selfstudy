#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
int ans = 0;
vector<int> vc;
vector<bool> visit;
vector<int> check;

int gcd(int x, int y) {
    if (y == 0) {
        return x;
    }

    return gcd(y, x % y);
}

void solve(int start, int dep) {
    if (dep == 2) {
        if (check[0] * check[1] != N) {
            return;
        }

        if (gcd(check[0], check[1]) == 1) {
            ans += 1;
        }

        return;
    }

    for (int i = start; i < vc.size(); i++) {
        if (visit[i]) {
            continue;
        }

        check.push_back(vc[i]);
        visit[i] = true;
        solve(i, dep + 1);
        check.pop_back();
        visit[i] = false;
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> N;

        if (N == 1) {
            vc.push_back(1);
            vc.push_back(1);
            visit.push_back(false);
            visit.push_back(false);
        }
        else {
            for (int i = 1; i * i < N; i++) {
                if (N % i == 0) {
                    vc.push_back(i);
                    vc.push_back(N / i);
                    visit.push_back(false);
                    visit.push_back(false);
                }
            }

            if (sqrt(N) == int(sqrt(N))) {
                vc.push_back(int(sqrt(N)));
                visit.push_back(false);
            }
        }

        solve(0, 0);

        cout << ans << "\n";

        vc.clear();
        visit.clear();
        check.clear();
        ans = 0;
    }

    return 0;
}