#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> vc;
int ans;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        vc.push_back(a);
    }

    sort(vc.begin(), vc.end());

    while (vc.size() > 1) {
        vc[vc.size() - 2] += vc[vc.size() - 1];
        vc[0] -= 1;
        ans += 1;

        vc.pop_back();

        if (vc[0] == 0) {
            for (int i = 0; i < vc.size(); i++) {
                vc[i] = vc[i + 1];
            }

            vc.pop_back();
        }
    }

    cout << ans;

    return 0;
}