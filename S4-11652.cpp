#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> vc;
    for (int i = 0; i < N; i++) {
        long long card;
        cin >> card;
        vc.push_back(card);
    }

    sort(vc.begin(), vc.end());

    long long card = vc[0];
    int cnt = 0, max_card = 0;
    for (int i = 1; i < N; i++) {
        if (vc[i] == vc[i - 1]) {
            cnt += 1;
        }
        else {
            cnt = 0;
        }

        if (cnt > max_card) {
            max_card = cnt;
            card = vc[i];
        }
    }

    cout << card;

    return 0;
}