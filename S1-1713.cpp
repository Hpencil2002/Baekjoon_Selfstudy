#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int vote[101];

int main() {
    cin >> N >> M;

    bool done;
    vector<pair<int, int>> vc = vector<pair<int, int>>(N);
    vector<int> ans;

    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;

        vote[num] += 1;
        done = false;

        for (int j = 0; j < N; j++) {
            if (vc[j].first == 0) {
                vc[j].first = num;
                vc[j].second = i;
                done = true;

                break;
            }
            else if (vc[j].first == num) {
                done = true;

                break;
            }
        }

        if (!done) {
            int index = 0;

            for (int j = 1; j < N; j++) {
                if (vote[vc[index].first] > vote[vc[j].first]) {
                    index = j;
                }
                else if (vote[vc[index].first] == vote[vc[j].first]) {
                    if (vc[index].second > vc[j].second) {
                        index = j;
                    }
                }
            }

            vote[vc[index].first] = 0;
            vc[index].first = num;
            vc[index].second = i;
        }
    }

    for (int i = 0; i < N; i++) {
        ans.push_back(vc[i].first);
    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] != 0) {
            cout << ans[i] << ' ';
        }
    }

    return 0;
}