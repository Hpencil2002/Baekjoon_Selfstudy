#include <iostream>
#include <string>
using namespace std;

#define MAX 1000

int num[] = { 2,2,2, 3,3,3, 4,4,4, 5,5,5, 6,6,6, 7,7,7,7, 8,8,8, 9,9,9,9 };
int cnt[] = { 1,2,3, 1,2,3, 1,2,3, 1,2,3, 1,2,3, 1,2,3,4, 1,2,3, 1,2,3,4 };
int pushed[MAX + 100];

int main() {
    int p, w;
    cin >> p >> w;

    string str;
    cin.ignore();
    getline(cin, str);

    int ans = 0;
    for (int i = 0; i <= str.length(); i++) {
        char alpha = str[i];

        if (alpha == 0) {
            break;
        }

        if (alpha == ' ') {
            ans += p;
            pushed[i] = 1;
            continue;
        }

        int tmp = alpha - 'A';
        pushed[i] = num[tmp];

        ans += cnt[tmp] * p;
        if (i != 0 && num[tmp] == pushed[i - 1]) {
            ans += w;
        }
    }

    cout << ans;

    return 0;
}