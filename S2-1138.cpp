#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> vc = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    vector<int> ans = vector<int>(N, 0);
    for (int i = 0; i < N; i++) {
        int index = 0;
        while (vc[i] != 0) {
            if (ans[index] == 0) {
                vc[i] -= 1;
            }

            index += 1;
        }

        while (ans[index] != 0) {
            index += 1;
        }

        ans[index] = i + 1;
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}