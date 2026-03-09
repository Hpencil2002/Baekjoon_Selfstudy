#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> crane;
vector<int> box;
int ans;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;

        crane.push_back(c);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int b;
        cin >> b;

        box.push_back(b);
    }

    sort(crane.begin(), crane.end());
    sort(box.begin(), box.end());

    if (crane.back() < box.back()) {
        cout << -1;

        return 0;
    }

    while (!box.empty()) {
        ans += 1;

        for (int i = crane.size() - 1; i >= 0; i--) {
            for (int j = box.size() - 1; j >= 0; j--) {
                if (crane[i] >= box[j]) {
                    box.erase(box.begin() + j);

                    break;
                }
            }
        }
    }

    cout << ans;

    return 0;
}