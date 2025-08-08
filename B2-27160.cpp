#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;

    map<string, int> mp;
    for (int i = 0; i < N; i++) {
        string S;
        int X;

        cin >> S >> X;
        mp[S] += X;
    }

    bool ans = false;

    if (mp["STRAWBERRY"] == 5) {
        ans = true;
    }
    else if (mp["BANANA"] == 5) {
        ans = true;
    }
    else if (mp["LIME"] == 5) {
        ans = true;
    }
    else if (mp["PLUM"] == 5) {
        ans = true;
    }

    cout << (ans ? "YES" : "NO");

    return 0;
}