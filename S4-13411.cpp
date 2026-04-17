#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
vector<pair<double, int>> vc;

int main() {
    cin >> N;
    vc.reserve(N);

    for (int i = 1; i <= N; i++) {
        double x, y, v;
        cin >> x >> y >> v;

        vc.push_back({ sqrt(x * x + y * y) / v, i });
    }

    sort(vc.begin(), vc.end());

    for (int i = 0; i < vc.size(); i++) {
        cout << vc[i].second << "\n";
    }

    return 0;
}