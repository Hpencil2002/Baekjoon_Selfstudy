#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string a, string b) {
    return a > b;
}

int main() {
    int N;
    cin >> N;

    vector<string> vc = vector<string>(N);
    vector<string> asc = vector<string>(N);
    vector<string> des = vector<string>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
        asc[i] = des[i] = vc[i];
    }

    sort(asc.begin(), asc.end());
    sort(des.begin(), des.end(), comp);

    if (vc == asc) {
        cout << "INCREASING";
    }
    else if (vc == des) {
        cout << "DECREASING";
    }
    else {
        cout << "NEITHER";
    }

    return 0;
}