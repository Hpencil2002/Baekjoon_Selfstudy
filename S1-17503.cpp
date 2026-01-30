#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, K;
long long sum;
int ans = -1;
priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> vc;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if (a.second < b.second) {
        return true;
    }
    else if (a.second == b.second) {
        return a.first > b.first;
    }
    else {
        return false;
    }
}

int main() {
    cin >> N >> M >> K;

    vc = vector<pair<int, int>>(K);
    for (int i = 0; i < K; i++) {
        cin >> vc[i].first >> vc[i].second;
    }

    sort(vc.begin(), vc.end(), cmp);

    for (int i = 0; i < N; i++) {
        pq.push(vc[i].first);
        sum += vc[i].first;
    }

    if (sum >= M) {
        cout << vc[N - 1].second;
    }
    else {
        for (int i = N; i < K; i++) {
            if (pq.top() < vc[i].first) {
                pq.push(vc[i].first);
                sum += ((long long)vc[i].first - (long long)pq.top());
                pq.pop();

                if (sum >= M) {
                    ans = vc[i].second;

                    break;
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}