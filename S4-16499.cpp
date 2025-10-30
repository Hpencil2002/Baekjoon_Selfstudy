#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    map<string, int> mp;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        sort(str.begin(), str.end());

        mp[str] = 1;
    }

    cout << mp.size();

    return 0;
}