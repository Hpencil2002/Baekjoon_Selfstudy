#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    cin.ignore();

    vector<int> vc;
    while (N--) {
        vc.clear();
        int ans = -1;

        string line;
        getline(cin, line);
        stringstream sstream(line);

        string num;
        while (getline(sstream, num, ' ')) {
            vc.push_back(stoi(num));
        }

        for (int i = 0; i < vc.size() - 1; i++) {
            for (int j = i + 1; j < vc.size(); j++) {
                int tmp = gcd(vc[i], vc[j]);
                ans = ans < tmp ? tmp : ans;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}