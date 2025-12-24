#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int A, B, N, M;
bool visit[100001];
queue<pair<int, int>> qu;

int main() {
    cin >> A >> B >> N >> M;

    visit[N] = true;
    qu.push({ N, 0 });

    while (!qu.empty()) {
        int pos = qu.front().first;
        int cnt = qu.front().second;
        qu.pop();

        if (pos == M) {
            cout << cnt;

            return 0;
        }

        int check[8] = {pos - 1, 
                        pos + 1, 
                        pos - A, 
                        pos + A, 
                        pos - B, 
                        pos + B, 
                        pos * A, 
                        pos * B };

        for (int i = 0; i < 8; i++) {
            if (check[i] >= 0 && check[i] <= 100000) {
                if (!visit[check[i]]) {
                    visit[check[i]] = true;
                    qu.push({ check[i], cnt + 1 });
                }
            }
        }
    }
}