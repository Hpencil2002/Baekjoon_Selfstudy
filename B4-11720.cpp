#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string num;
    int ans = 0;

    cin >> N >> num;
    for (int i = 0; i < num.length(); i++) {
        ans += num[i] - '0';
    }

    cout << ans;

    return 0;
}