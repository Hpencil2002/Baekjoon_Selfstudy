#include <iostream>
#include <vector>
using namespace std;

int N, q, t, k;
vector<int> vc[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;

        vc[a].push_back(b);
        vc[b].push_back(a);
    }

    cin >> q;
    while (q--) {
        cin >> t >> k;

        if (t == 1) {
            if (vc[k].size() >= 2) {
                cout << "yes\n";
            }
            else {
                cout << "no\n";
            }
        }
        else {
            cout << "yes\n";
        }
    }

    return 0;
}