#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string str;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    while (true) {
        cin >> str >> n;
        if (cin.eof()) {
            break;
        }

        vector<char> vc;
        for (int i = 0; i < str.size(); i++) {
            vc.push_back(str[i]);
        }
    
        sort(vc.begin(), vc.end());
    
        int idx = 1;
        bool valid = false;
    
        do {
            if (idx == n) {
                cout << str << ' ' << n << " = ";
                for (int i = 0; i < str.size(); i++) {
                    cout << vc[i];
                }
    
                valid = true;
                cout << "\n";
            }
    
            idx += 1;
        } while (next_permutation(vc.begin(), vc.end()));
    
        if (!valid) {
            cout << str << ' ' << n << " = No permutation\n";
        }
    }

    return 0;
}