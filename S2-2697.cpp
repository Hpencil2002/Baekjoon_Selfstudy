#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int num[10];

int main() {
    int T;
    cin >> T;

    int i = 0;
    string ans = "";
    while (T--) {
        string A;
        cin >> A;

        memset(num, 0, sizeof(num));

        for (i = A.size() - 1; i > 0; i--) {
            if (A[i - 1] < A[i]) {
                for (int j = i - 1; j < A.size(); j++) {
                    num[A[j] - '0'] += 1;
                }
                ans.append(A.substr(0, i - 1));

                for (int j = A[i - 1] - '0' + 1; j < 10; j++) {
                    if (num[j] > 0) {
                        num[j] -= 1;
                        ans.append(to_string(j));

                        break;
                    }
                }

                for (int j = 0; j < 10; j++) {
                    while (num[j]--) {
                        ans.append(to_string(j));
                    }
                }
                ans.append("\n");

                break;
            }
        }

        if (i == 0) {
            ans.append("BIGGEST\n");
        }
    }

    cout << ans;

    return 0;
}