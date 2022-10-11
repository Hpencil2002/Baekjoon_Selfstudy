#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, num;
    vector<int> v;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> num;
        cout << binary_search(v.begin(), v.end(), num) << "\n";
    }

    return 0;
}