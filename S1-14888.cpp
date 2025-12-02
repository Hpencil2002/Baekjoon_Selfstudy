#include <iostream>
using namespace std;

int N;
int arr[11];
int oper[4];
int maxAns = -1000000001;
int minAns = 1000000001;

void solve(int res, int index) {
    if (index == N) {
        if (res > maxAns) {
            maxAns = res;
        }
        if (res < minAns) {
            minAns = res;
        }

        return;
    }

    for (int i = 0; i < 4; i++) {
        if (oper[i] > 0) {
            oper[i] -= 1;

            if (i == 0) {
                solve(res + arr[index], index + 1);
            }
            else if (i == 1) {
                solve(res - arr[index], index + 1);
            }
            else if (i == 2) {
                solve(res * arr[index], index + 1);
            }
            else {
                solve(res / arr[index], index + 1);
            }

            oper[i] += 1;
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> oper[i];
    }

    solve(arr[0], 1);

    cout << maxAns << "\n" << minAns;

    return 0;
}