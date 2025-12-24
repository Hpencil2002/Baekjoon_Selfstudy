#include <iostream>
#include <vector>
using namespace std;

int k, sum;
int ans;
int arr[15];
vector<bool> vc;

void dfs(int index, int weight) {
    if (index == k) {
        if (weight >= 0) {
            vc[weight] = true;
        }

        return;
    }

    dfs(index + 1, weight);
    dfs(index + 1, weight + arr[index]);
    dfs(index + 1, weight - arr[index]);
}

int main() {
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    vc.resize(sum + 1, false);

    dfs(0, 0);

    for (int i = 1; i <= sum; i++) {
        if (vc[i] == false) {
            ans += 1;
        }
    }

    cout << ans;

    return 0;
}