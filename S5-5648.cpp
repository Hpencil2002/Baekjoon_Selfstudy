#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> vc = vector<long long>(n);
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;

        reverse(tmp.begin(), tmp.end());

        vc[i] = stol(tmp);
    }

    sort(vc.begin(), vc.end());

    for (int i = 0; i < n; i++) {
        cout << vc[i] << "\n";
    }

    return 0;
}