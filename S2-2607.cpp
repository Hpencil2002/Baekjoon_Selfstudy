#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int alpha[26] = { 0, };

int main() {
    int N;
    cin >> N;

    string origin, comp;
    cin >> origin;

    int origin_len = origin.size();
    for (int i = 0; i < origin_len; i++) {
        alpha[origin[i] - 'A'] += 1;
    }

    int ans = 0;
    for (int t = 0; t < N - 1; t++) {
        cin >> comp;

        int comp_len = comp.size();
        int ccopy[26];
        copy(alpha, alpha + 26, ccopy);

        int same = 0;
        for (int i = 0; i < comp_len; i++) {
            if (ccopy[comp[i] - 'A'] > 0) {
                ccopy[comp[i] - 'A'] -= 1;
                same += 1;
            }
        }

        if (origin_len == comp_len) {
            if (same == origin_len || same == origin_len - 1) {
                ans += 1;
            }
        }
        else if (origin_len - 1 == comp_len && same == origin_len - 1) {
            ans += 1;
        }
        else if (origin_len + 1 == comp_len && same == origin_len) {
            ans += 1;
        }
        else {
            continue;
        }
    }

    cout << ans;

    return 0;
}