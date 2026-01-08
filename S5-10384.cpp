#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;

int main() {
    cin >> n;
    cin.ignore();

    for (int t = 1; t <= n; t++) {
        string str;
        getline(cin, str);

        transform(str.begin(), str.end(), str.begin(), :: tolower);

        int arr[26] = { 0, };
        int cnt = 0;
        int len = str.length();

        for (int i = 0; i < len; i++) {
            cnt = str[i] - 97;
            arr[cnt] += 1;
        }

        int cnt1 = 0;
        int cnt2 = 0;
        int cnt3 = 0;

        for (int i = 0; i < 26; i++) {
            if (arr[i] != 0) {
                cnt1 += 1;
            }
            if (arr[i] == 2) {
                cnt2 += 1;
            }
            if (arr[i] >= 3) {
                cnt3 += 1;
            }
        }

        if (cnt3 == 26) {
            cout << "Case " << t << ": " << "Triple pangram!!!\n";
        }
        else if (cnt2 == 26 || cnt2 + cnt3 == 26) {
            cout << "Case " << t << ": " << "Double pangram!!\n";
        }
        else if (cnt1 == 26) {
            cout << "Case " << t << ": " << "Pangram!\n";
        }
        else {
            cout << "Case " << t << ": " << "Not a pangram\n";
        }
    }

    return 0;
}