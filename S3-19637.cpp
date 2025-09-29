#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<pair<int, string>> vc = vector<pair<int, string>>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i].second >> vc[i].first;
    }

    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;

        int low = 0;
        int high = vc.size() - 1;
        int res = high;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (vc[mid].first >= num) {
                high = mid - 1;
                res = mid;
            }
            else {
                low = mid + 1;
            }
        }

        cout << vc[res].second << "\n";
    }

    return 0;
}