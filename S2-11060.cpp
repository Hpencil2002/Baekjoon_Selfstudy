#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> vc;
    for (int i = 0; i < N; i++) {
        int jump;
        cin >> jump;

        vc.push_back(jump);
    }

    if (N == 1) {
        cout << 0;

        return 0;
    }

    vector<int> count = vector<int>(N);
    fill_n(count.begin(), N, -1);
    count[0] = 0;

    for (int i = 0; i < N - 1; i++) {
        if (count[i] < 0) {
            continue;
        }

        int dis = vc[i];
        for (int d = 1; d <= dis; d++) {
            if (N <= i + d) {
                break;
            }
            if (count[i + d] > 0) {
                continue;
            }

            count[i + d] = count[i] + 1;
        }
    }

    cout << count[N - 1];

    return 0;
}