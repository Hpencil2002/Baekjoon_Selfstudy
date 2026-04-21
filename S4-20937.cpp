#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

int N;
unordered_map<int, int> ump;
int ans;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        ump[num] += 1;
        ans = max(ans, ump[num]);
    }

    cout << ans;

    return 0;
}