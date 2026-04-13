#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int K;
int arr[50002];
vector<int> v;
vector<int> l;

int main() {
    int T;
    cin >> T;

    for (int i = 1; i < 50002; i++) {
        arr[i] = i;
    }
    for (int i = 2; i < 50002; i++) {
        if (!arr[i]) {
            continue;
        }
        else {
            v.push_back(i);
        }

        for (int j = i + i; j < 50002; j += i) {
            arr[j] = 0;
        }
    }

    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (i != j) {
                l.push_back(v[i] * v[j]);
            }
        }
    }
    sort(l.begin(), l.end());

    while (T--) {
        cin >> K;

        int ans = 0;
        int left = 0;
        int right = l.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (l[mid] >= K) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        cout << l[ans] << "\n";
    }

    return 0;
}