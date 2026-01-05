#include <iostream>
#include <vector>
using namespace std;

int arr[10];
int ans, cnt;
vector<int> vc;

void solve(int index) {
    if (vc.size() > 2 && vc[vc.size() - 3] == vc[vc.size() - 2] && vc[vc.size() - 2] == vc.back()) {
        return;
    }

    if (index == 10) {
        if (cnt > 4) {
            ans += 1;
        }
    }
    else {
        for (int i = 1; i < 6; i++) {
            vc.emplace_back(i);
            if (arr[index] == i) {
                cnt += 1;
            }

            solve(index + 1);

            vc.pop_back();
            if (arr[index] == i) {
                cnt -= 1;
            }
        }
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    solve(0);

    cout << ans;

    return 0;
}