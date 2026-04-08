#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> vc = vector<string>(6);
vector<string> candidates;

int main() {
    for (int i = 0; i < 6; i++) {
        cin >> vc[i];
    }

    do {
        string str = "";
        vector<string> vec;

        for (int i = 0; i < 3; i++) {
            str += vc[i];
            vec.push_back(vc[i]);
        }

        vector<string> sero;
        bool isValid = true;
        for (int i = 0; i < 3; i++) {
            string tmp = "";

            for (int j = 0; j < 3; j++) {
                tmp += vec[j][i];
            }

            sero.push_back(tmp);
        }

        for (int i = 3; i < 6; i++) {
            auto iter = find(sero.begin(), sero.end(), vc[i]);

            if (iter == sero.end()) {
                isValid = false;

                break;
            }
            else {
                sero.erase(iter);
            }
        }

        if (isValid) {
            candidates.push_back(str);
        }
    } while (next_permutation(vc.begin(), vc.end()));

    if (candidates.size() == 0) {
        cout << 0;
    }
    else {
        sort(candidates.begin(), candidates.end());

        for (int i = 0; i < 9; i++) {
            cout << candidates[0][i];

            if (i % 3 == 2) {
                cout << "\n";
            }
        }
    }

    return 0;
}