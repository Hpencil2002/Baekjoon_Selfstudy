#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        sum1 += num;
    }

    for (int i = 0; i < N; i++) {
        sum2 += i;
    }

    cout << sum1 - sum2;

    return 0;
}