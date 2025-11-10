#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    long long maxNum = -1;
    long long maxFreq = 0;
    unordered_map<long long, int> ump;
    while (n--) {
        int m;
        cin >> m;

        for (int i = 0; i < m; i++) {
            long long num;
            cin >> num;

            ump[num] += 1;
            if (ump[num] > maxFreq) {
                maxFreq = ump[num];
                maxNum = num;
            }
        }

        int half = m / 2;
        if (maxFreq > half) {
            cout << maxNum << "\n";
        }
        else {
            cout << "SYJKGW\n";
        }

        ump.clear();
        maxFreq = 0;
        maxNum = -1;
    }

    return 0;
}