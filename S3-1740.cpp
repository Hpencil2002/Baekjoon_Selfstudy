#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main() {
    long long N;
    cin >> N;

    string tmp = bitset<64>(N).to_string();

    long long ans = 0;
    long long seq = 1;
    for (int i = tmp.size() - 1; i > -1; i--) {
        if (tmp[i] == '1') {
            ans += seq;
        }

        seq *= 3;
    }

    cout << ans;

    return 0;
}