#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
    int N;
    string input;
    vector<string> num;
    int ans = 1;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        reverse(input.begin(), input.end());
        num.push_back(input);
    }

    while (true) {
        set<string> s;

        for (int i = 0; i < N; i++) {
            s.insert(num[i].substr(0, ans));
        }

        if (s.size() == N) {
            break;
        }
        else {
            ans += 1;
        }
    }

    cout << ans;

    return 0;
}