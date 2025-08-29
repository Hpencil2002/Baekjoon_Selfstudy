#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> vc;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        vc.push_back({a, b});
    }

    sort(vc.begin(), vc.end());

    int time = 0;
    for (int i = 0; i < N; i++) {
        time = max(vc[i].first, time);
        time += vc[i].second;
    }

    cout << time;

    return 0;
}