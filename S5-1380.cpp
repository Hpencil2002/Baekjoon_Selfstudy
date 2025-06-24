#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int cnt = 1;

    while (true) {
        int n;
        cin >> n;
    
        if (n == 0) {
            break;
        }

        cin.ignore();
    
        vector<string> names;
        for (int i = 0; i < n; i++) {
            string name;
            getline(cin, name);
            names.push_back(name);
        }
    
        int earring[101] = { 0, };
        for (int i = 0; i < 2 * n - 1; i++) {
            int num;
            char tmp;

            cin >> num >> tmp;
            earring[num - 1] += 1;
        }

        for (int i = 0; i < n; i++) {
            if (earring[i] == 1) {
                cout << cnt << ' ' << names[i] << "\n";
                cnt += 1;
            }
        }
    }

    return 0;
}