#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        vector<int> vc(10);

        for (int i = 0; i < 10; i++) {
            cin >> vc[i];
        }

        sort(vc.begin(), vc.end(), greater<int>());

        cout << vc[2] << "\n";
    }

    return 0;
}