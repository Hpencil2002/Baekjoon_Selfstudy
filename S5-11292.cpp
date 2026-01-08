#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<string, double>> vc;

bool comp(pair<string, double> a, pair<string, double> b) {
    return a.second > b.second;
}

int main() {
    while (true) {
        cin >> N;
        if (N == 0) {
            return 0;
        }

        vc.clear();
        vc = vector<pair<string, double>>(N);
        for (int i = 0; i < N; i++) {
            cin >> vc[i].first >> vc[i].second;
        }

        sort(vc.begin(), vc.end(), comp);

        cout << vc[0].first << ' ';
        for (int i = 1; i < N; i++) {
            if (vc[0].second == vc[i].second) {
                cout << vc[i].first << ' ';
            }
            else {
                break;
            }
        }
        cout << "\n";
    }
}