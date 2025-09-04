#include <iostream>
#include <vector>
using namespace std;

vector<long long> ans = { 0, 1, 2 };

int main() {
    int N;
    cin >> N;

    long long tmp;
    for (int i = 3; i <= N; i++) {
        tmp = ans[i - 1] + ans[i - 2];
        ans.push_back(tmp % 15746);
    }

    cout << ans[N] % 15746;

    return 0;
}