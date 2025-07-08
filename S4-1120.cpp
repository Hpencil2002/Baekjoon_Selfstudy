#include <iostream>
#include <string>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;

    int ans = 50;
    for (int i = 0; i <= B.size() - A.size(); i++) {
        int cnt = 0;

        for (int j = 0; j < A.size(); j++) {
            if (A[j] != B[j + i]) {
                cnt += 1;
            }
        }

        if (cnt < ans) {
            ans = cnt;
        }
    }

    cout << ans;

    return 0;
}