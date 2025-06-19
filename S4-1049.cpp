#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int set = 1000, single = 1000;

int main() {
    cin >> N >> M;

    int x = 0, y = 0;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        set = min(set, x);
        single = min(single, y);
    }

    cout << min((N/6 + 1) * set, min(N / 6 * set + N % 6 * single, N * single));

    return 0;
}