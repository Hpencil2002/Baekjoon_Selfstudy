#include <iostream>
#include <algorithm>
using namespace std;

int n;
int ans;
int arr[1001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n, greater<int>());

    for (int i = 1; i < n; i++) {
        ans += (arr[0] + arr[i]);
    }

    cout << ans;

    return 0;
}