#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N, K, Q, M, S, E;
int ans;
vector<int> student;
map<int, int> sleep, attend;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K >> Q >> M;

    student = vector<int>(N + 3, 1);
    student[2] = 0;

    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;

        sleep[x] = 1;
    }
    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;

        attend[x] = 1;
    }

    for (auto a : attend) {
        int tmp = a.first;
        if (sleep[tmp]) {
            continue;
        }

        for (int i = 1; tmp <= N + 2; i++) {
            if (!sleep[tmp]) {
                student[tmp] = 0;
            }

            tmp = i * a.first;
        }
    }

    for (int i = 3; i <= N + 2; i++) {
        student[i] += student[i - 1];
    }

    for (int i = 0; i < M; i++) {
        cin >> S >> E;
        cout << student[E] - student[S - 1] << "\n";
    }

    return 0;
}