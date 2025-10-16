#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<double> vc = vector<double>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    sort(vc.begin(), vc.end());

    for (int i = 0; i < 7; i++) {
        printf("%.3f\n", vc[i]);
    }

    return 0;
}