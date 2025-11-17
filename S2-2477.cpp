#include <iostream>
using namespace std;

pair<int, int> len[12];

int main() {
    int K;
    cin >> K;

    for (int i = 0; i < 6; i++) {
        int d, l;
        cin >> d >> l;

        len[i] = len[i + 6] = { d, l };
    }

    int big = 0, small = 0;
    for (int i = 3; i < 12; i++) {
        if (len[i].first == len[i - 2].first && len[i - 1].first == len[i - 3].first) {
            big = len[i + 1].second * len[i + 2].second;
            small = len[i - 1].second * len[i - 2].second;
            break;
        }
    }

    cout << K * (big - small);

    return 0;
}