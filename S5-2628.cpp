#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    int N, d, n;
    cin >> N;

    vector<int> w, h;
    w.push_back(0);
    h.push_back(0);
    w.push_back(c);
    h.push_back(r);

    for (int i = 0; i < N; i++) {
        cin >> d >> n;
        if (d) {
            h.push_back(n);
        }
        else {
            w.push_back(n);
        }
    }

    sort(w.begin(), w.end());
    sort(h.begin(), h.end());

    vector<int> nw, nh;
    for (int i = 1; i < w.size(); i++) {
        nw.push_back(w[i] - w[i - 1]);
    }
    for (int i = 1; i < h.size(); i++) {
        nh.push_back(h[i] - h[i - 1]);
    }

    sort(nw.begin(), nw.end());
    sort(nh.begin(), nh.end());

    int ans = nw[nw.size() - 1] * nh[nh.size() - 1];
    cout << ans;

    return 0;
}