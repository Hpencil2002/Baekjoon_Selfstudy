#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N1, N2;
    cin >> N1 >> N2;

    vector<pair<char, int>> vc;
    string str;

    cin >> str;
    for (int i = N1 - 1; i >= 0; i--) {
        vc.push_back({str[i], 0});
    }

    cin >> str;
    for (int i = 0; i < N2; i++) {
        vc.push_back({str[i], 1});
    }

    int T;
    cin >> T;

    int time = 0;
    while (time != T) {
        for (int i = 0; i < N1 + N2 - 1; i++) {
            if (vc[i].second == 0 && vc[i + 1].second == 1) {
                swap(vc[i], vc[i + 1]);
                i += 1;
            }
        }

        time += 1;
    }

    for (int i = 0; i < N1 + N2; i++) {
        cout << vc[i].first;
    }

    return 0;
}