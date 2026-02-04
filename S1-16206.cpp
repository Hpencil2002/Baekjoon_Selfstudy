#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> vc1;
vector<int> vc2;
int ans;

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        if (a < 10) {
            continue;
        }
        else if (a == 10) {
            ans += 1;
        }
        else if (a % 10 == 0) {
            vc1.push_back(a);
        }
        else {
            vc2.push_back(a);
        }
    }

    sort(vc1.begin(), vc1.end());
    sort(vc2.begin(), vc2.end());

    vc1.insert(vc1.end(), vc2.begin(), vc2.end());

    while (M > 0 && !vc1.empty()) {
        int tmp = vc1[0];
        int b = tmp / 10;

        if (tmp % 10 == 0) {
            if (b - 1 <= M) {
                ans += b;
                M -= (b - 1);
            }
            else {
                ans += M;

                break;
            }
        }
        else {
            if (b <= M) {
                ans += b;
                M -= b;
            }
            else {
                ans += M;

                break;
            }
        }

        vc1.erase(vc1.begin());
    }

    cout << ans;

    return 0;
}