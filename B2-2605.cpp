#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> vc = vector<int>(N);
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;

        vc.insert(vc.begin() + num, i);
    }

    for (int i = N - 1; i >= 0; i--) {
        cout << vc[i] << ' ';
    }

    return 0;
}