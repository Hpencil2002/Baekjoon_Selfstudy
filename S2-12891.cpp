#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int S, P;
    string str;

    cin >> S >> P >> str;

    int start, end, ans = 0;
    vector<int> key = vector<int>(100, 0);
    vector<int> ACGT = vector<int>(100, 0);

    cin >> key['A'] >> key['C'] >> key['G'] >> key['T'];

    start = 0;
    end = start + P - 1;
    for (int i = start; i <= end; i++) {
        ACGT[str[i]] += 1;
    }

    while (end < str.size()) {
        if (key['A'] <= ACGT['A'] && key['C'] <= ACGT['C'] && key['G'] <= ACGT['G'] && key['T'] <= ACGT['T']) {
            ans += 1;
        }

        ACGT[str[start++]] -= 1;
        ACGT[str[++end]] += 1;
    }

    cout << ans;

    return 0;
}