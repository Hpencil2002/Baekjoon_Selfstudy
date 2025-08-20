#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string S;
    cin >> S;

    vector<string> vc;
    for (int i = 0; i < S.size(); i++) {
        string tmp = S.substr(i, S.size() - i);
        vc.push_back(tmp);
    }

    sort(vc.begin(), vc.end());

    for (int i = 0; i < vc.size(); i++) {
        cout << vc[i] << "\n";
    }

    return 0;
}