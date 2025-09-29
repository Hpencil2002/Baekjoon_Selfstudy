#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<pair<int, string>> vc;
map<string, int> mp;

int main() {
    int K, L;
    cin >> K >> L;

    for (int i = 0; i < L; i++) {
        string num;
        cin >> num;

        mp[num] = i + 1;
    }

    for (auto i = mp.begin(); i != mp.end(); i++) {
        string a = i->first;
        int b = i->second;
        vc.push_back({ b, a });
    }

    sort(vc.begin(), vc.end());

    for (int i = 0; i < min(K, (int)vc.size()); i++) {
        cout << vc[i].second << "\n";
    }

    return 0;
}