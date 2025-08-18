#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> vc = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    sort(vc.begin(), vc.end(), greater<int>());

    for (int i = 0; i < N; i++) {
        cout << vc[i] << "\n";
    }

    return 0;
}