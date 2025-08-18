#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, L;
    cin >> N >> L;

    vector<int> vc = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    sort(vc.begin(), vc.end());

    for (int i = 0; i < N; i++) {
        if (L >= vc[i]) {
            L += 1;
        }
    }

    cout << L;

    return 0;
}