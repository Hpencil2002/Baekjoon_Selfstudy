#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<int> split(string input, char delimiter) {
    vector<int> ans;
    stringstream ss(input);
    string tmp;

    while (getline(ss, tmp, delimiter)) {
        ans.push_back(stoi(tmp));
    }

    return ans;
}

int main() {
    int N, K;
    cin >> N >> K;

    string str;
    cin >> str;
    vector<int> vc = split(str, ',');

    while (K--) {
        vector<int> vc2;
        for (int i = 0; i < vc.size() - 1; i++) {
            vc2.push_back(vc[i + 1] - vc[i]);
        }

        vc = vc2;
    }

    for (int i = 0; i < vc.size(); i++) {
        cout << vc[i];
        if (i != vc.size() - 1) {
            cout << ",";
        }
    }

    return 0;
}