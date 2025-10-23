#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> vc;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        vc.push_back(tmp);
    }

    int K;
    cin >> K;

    int num = N / 2;
    while (num >= 1) {
        int ssize = N / num;
        for (int i = 0; i < N - 1; i += ssize) {
            sort(vc.begin() + i, vc.begin() + i + ssize);
        }

        if (num == K) {
            for (int i = 0; i < N; i++) {
                cout << vc[i] << ' ';
            }
            cout << "\n";

            return 0;
        }

        num /= 2;
    }
}