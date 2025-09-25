#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int sum = 0;
    vector<int> vc = vector<int>(N + 1);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        sum += num;
        vc[i + 1] = sum;
    }

    int M;
    cin >> M;
    while (M--) {
        int start, end;
        cin >> start >> end;

        cout << vc[end] - vc[start - 1] << "\n";
    }

    return 0;
}