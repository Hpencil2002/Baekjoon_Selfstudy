#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
vector<int> vc;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        vc.push_back(num);
    }

    sort(vc.begin(), vc.end());

    int start = 0;
    int end = N - 1;
    int Min = 2e9 + 1;
    int sign = 1;

    while (start < end) {
        int tmp = vc[start] + vc[end];
        if (abs(tmp) < Min) {
            Min = abs(tmp);
            sign = tmp / abs(tmp);
        }

        if (tmp > 0) {
            end -= 1;
        }
        else {
            start += 1;
        }
    }

    cout << Min * sign;

    return 0;
}