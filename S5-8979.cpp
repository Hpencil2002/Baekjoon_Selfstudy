#include <iostream>
using namespace std;

int ans;
int gold[1001];
int silver[1001];
int bronze[1001];

int main() {
    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int index;
        cin >> index;
        cin >> gold[index] >> silver[index] >> bronze[index];
    }

    for (int i = 1; i <= N; i++) {
        if (gold[i] > gold[K]) {
            ans += 1;
        }
        else if (gold[i] == gold[K]) {
            if (silver[i] > silver[K]) {
                ans += 1;
            }
            else if (silver[i] == silver[K]) {
                if (bronze[i] > bronze[K]) {
                    ans += 1;
                }
            }
        }
    }

    cout << ans + 1;

    return 0;
}