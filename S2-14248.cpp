#include <iostream>
using namespace std;

int n, s;
int ans;
int arr[100001];
bool visit[100001] = { false, };

void dfs(int cur) {
    if (cur < 1 || cur > n) {
        return;
    }

    visit[cur] = true;
    dfs(cur + arr[cur]);
    dfs(cur - arr[cur]);
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    cin >> s;

    dfs(s);

    for (int i = 1; i <= n; i++) {
        if (visit[i]) {
            ans += 1;
        }
    }

    cout << ans;

    return 0;
}