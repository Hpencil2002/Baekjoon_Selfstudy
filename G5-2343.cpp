#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> vc;
int ans;

int getCount(int amount) {
    int sum = 0;
    int res = 1;

    for (int i = 0; i < vc.size() - 1; i++) {
        sum += vc[i];

        if (sum + vc[i + 1] > amount) {
            sum = 0;
            res += 1;
        }
    }

    return res;
}

int main() {
    cin >> N >> M;

    int start = -1;
    int end = 0;
    int mid;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        vc.push_back(tmp);
        end += tmp;
        start = max(start, tmp);
    }

    while (start <= end) {
        mid = (start + end) / 2;

        if (getCount(mid) <= M) {
            end = mid - 1;
            ans = mid;
        }
        else {
            start = mid + 1;
        }
    }

    cout << ans;

    return 0;
}