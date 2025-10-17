#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> vc;
        int index;
        int max_people = 0;
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            vc.push_back(tmp);

            if (tmp > max_people) {
                max_people = tmp;
                index = i;
            }
        }

        sort(vc.begin(), vc.end(), greater<int>());

        int cnt = 0;
        int sum = 0;
        for (int i = 0; i < vc.size(); i++) {
            if (vc[0] == vc[1]) {
                cnt += 1;
            }

            sum += vc[i];
        }

        if (cnt == 0) {
            if (sum - vc[0] <  vc[0]) {
                cout << "majority winner " << index << "\n";
            }
            else if (sum - vc[0] >= vc[0]) {
                cout << "minority winner " << index << "\n";
            }
        }
        else if (cnt >= 1) {
            cout << "no winner\n";
        }
    }

    return 0;
}