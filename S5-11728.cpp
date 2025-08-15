#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> vc;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        vc.push_back(tmp);
    }
    for (int i = 0; i < M; i++) {
        int tmp;
        cin >> tmp;
        vc.push_back(tmp);
    }

    sort(vc.begin(), vc.end());

    for (int i = 0; i < vc.size(); i++) {
        cout << vc[i] << ' ';
    }

    return 0;
}