#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> prime;
bool visit[40000];
map<int, int> a, b;

void init(int num, int map_num) {
    if (map_num == 0) {
        for (auto o : prime) {
            if (num % o == 0) {
                a[o] += 1;
                init(num / o, 0);

                return;
            }
        }

        if (num != 1) {
            a[num] += 1;
        }
    }
    else {
        for (auto o : prime) {
            if (num % o == 0) {
                b[o] += 1;
                init(num / o, 1);

                return;
            }
        }

        if (num != 1) {
            b[num] += 1;
        }
    }
}

int main() {
    int N, M;
    long long ans = 1;
    bool isBigger = false;

    for (int i = 2; i < 40000; i++) {
        if (visit[i]) {
            continue;
        }

        prime.push_back(i);
        for (int j = 2 * i; j < 40000; j += i) {
            visit[j] = true;
        }
    }

    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        init(num, 0);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        init(num, 1);
    }

    for (auto o : a) {
        if (!b[o.first]) {
            continue;
        }

        int cnt = min(o.second, b[o.first]);
        while (cnt--) {
            ans *= o.first;

            if (ans >= 1000000000) {
                ans %= 1000000000;
                isBigger = true;
            }
        }
    }

    if (isBigger) {
        printf("%09lld", ans);
    }
    else {
        cout << ans;
    }

    return 0;
}