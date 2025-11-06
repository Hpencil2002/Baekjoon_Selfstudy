#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, A, B, C;
    cin >> N >> A >> B >> C;

    vector<int> vc = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    sort(vc.begin(), vc.end(), greater<int>());

    int cal = C / A;
    int ans = cal;

    int totalPrice = A;
    int totalCal = C;
    for (int i = 0; i < N; i++) {
        totalPrice += B;
        totalCal += vc[i];

        if (ans < totalCal / totalPrice) {
            ans = totalCal / totalPrice;
        }
    }

    cout << ans;

    return 0;
}