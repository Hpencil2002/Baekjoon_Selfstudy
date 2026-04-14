#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> vc;
int ansChoco, ansDay;

int main() {
    cin >> N >> K;

    vc = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    sort(vc.begin(), vc.end());

    for (int i = 1; i < N; i++) {
        if (vc[i] > vc[0]) {
            ansChoco += vc[i] - vc[0];
            ansDay += 1;
        }
    }

    cout << ansChoco << ' ' << ansDay;

    return 0;
}