#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 1000001;
int arr[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> vc;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        vc.push_back(arr[i]);
    }

    sort(vc.begin(), vc.end());
    vc.erase(unique(vc.begin(), vc.end()), vc.end());

    for (int i = 0; i < n; i++) {
        int index = lower_bound(vc.begin(), vc.end(), arr[i]) - vc.begin();
        cout << index << " ";
    }

    return 0;
}