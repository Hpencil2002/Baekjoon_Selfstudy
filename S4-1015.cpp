#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;

    cin >> N;
    vector<pair<int, int>> A(N);
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < N; i++) {
        P[A[i].second] = i;
    }

    for (int r : P) {
        cout << r << ' ';
    }

    return 0;
}