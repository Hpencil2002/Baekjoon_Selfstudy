#include <iostream>
#include <queue>
using namespace std;

int N;
int sum, ans;
priority_queue<int, vector<int>, greater<int>> pqu;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        pqu.push(num);
    }

    while (pqu.size() != 1) {
        int tmp1 = pqu.top();
        pqu.pop();
        int tmp2 = pqu.top();
        pqu.pop();

        sum = tmp1 + tmp2;
        ans += tmp1 * tmp2;

        pqu.push(sum);
    }

    cout << ans;

    return 0;
}