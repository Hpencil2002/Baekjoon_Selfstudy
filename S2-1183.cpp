#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> vc;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        vc.push_back(a - b);
    }

    sort(vc.begin(), vc.end());

    if (N % 2 == 1) {
        cout << 1;
    }
    else {
        cout << vc[N / 2] - vc[N / 2 - 1] + 1;
    }

    return 0;
}