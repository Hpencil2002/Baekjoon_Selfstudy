#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    int cnt = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        bool alp[26] = { false, };
        string str;

        cin >> str;
        alp[str[0] - 'a'] = true;
        for (int j = 1; j < str.size(); j++) {
            if (str[j] == str[j - 1]) {
                continue;
            }
            else if (str[j] != str[j - 1] && alp[str[j] - 'a']) {
                cnt += 1;
                break;
            }
            else {
                alp[str[j] - 'a'] = true;
            }
        }
    }

    cout << N - cnt;

    return 0;
}