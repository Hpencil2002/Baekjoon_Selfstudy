#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int ans;
vector<int> vc;
bool check[1000010];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        vc.push_back(tmp);
        check[tmp] = true;
    }

    for (int i = 0; i < 1000001; i++) {
        if (check[i]) {
            int m = vc[0];
            int m_cnt = 0;

            for (int j = 0; j < N; j++) {
                if (vc[j] == i) {
                    continue;
                }

                if (m == vc[j]) {
                    m_cnt += 1;
                }
                else if (m != vc[j]) {
                    m = vc[j];
                    m_cnt = 1;
                }
                else if (j == N - 1) {
                    m_cnt += 1;
                }

                ans = max(ans, m_cnt);
            }
        }
    }

    cout << ans;

    return 0;
}