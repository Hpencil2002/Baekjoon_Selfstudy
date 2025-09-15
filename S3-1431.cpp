#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string a, string b) {
    if (a.size() != b.size()) {
        return a.size() < b.size();
    }
    else {
        int tmp_a = 0, tmp_b = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] >= '0' && a[i] <= '9') {
                tmp_a += a[i] - '0';
            }
        }
        for (int i = 0; i < b.size(); i++) {
            if (b[i] >= '0' && b[i] <= '9') {
                tmp_b += b[i] - '0';
            }
        }

        if (tmp_a != tmp_b) {
            return tmp_a < tmp_b;
        }
        else {
            return a < b;
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<string> vc = vector<string>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    sort(vc.begin(), vc.end(), comp);

    for (int i = 0; i < N; i++) {
        cout << vc[i] << "\n";
    }

    return 0;
}