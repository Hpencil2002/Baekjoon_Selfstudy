#include <iostream>
#include <vector>
using namespace std;

int N, S, ans;
vector<int> vc;

void solve(int index, int tmp) {
    if (index == N) {
        return;
    }

    if (tmp + vc[index] == S) {
        ans += 1;
    }

    solve(index + 1, tmp);
    solve(index + 1, tmp + vc[index]);
}

int main() {
    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        int num;
        cin >>num;
        vc.push_back(num);
    }

    solve(0, 0);

    cout << ans;

    return 0;
}