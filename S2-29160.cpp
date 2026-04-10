#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;
long long ans;
vector<priority_queue<int>> vc = vector<priority_queue<int>>(12);
bool check[12];

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int p, w;
        cin >> p >> w;

        vc[p].push(w);
        if (!check[p]) {
            check[p] = true;
        }
    }

    for (int i = 0; i < K; i++) {
        for (int j = 1; j <= 11; j++) {
            if (check[j]) {
                int tmp = vc[j].top();
                if (tmp == 1) {
                    break;
                }

                vc[j].pop();
                tmp -= 1;
                vc[j].push(tmp);
            }
        }
    }

    for (int i = 1; i <= 11; i++) {
        if (check[i]) {
            ans += vc[i].top();
        }
    }

    cout << ans;

    return 0;
}