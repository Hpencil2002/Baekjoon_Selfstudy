#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long A, B;
char D;
int ans;
vector<bool> vc;

void isPrime() {
    vc[1] = false;

    for (long long i = 2; i <= B; i++) {
        if (!vc[i]) {
            continue;
        }

        for (long long j = 2 * i; j <= B; j += i) {
            vc[j] = false;
        }
    }
}

int main() {
    cin >> A >> B >> D;

    vc.resize(B + 10, true);
    isPrime();

    for (int i = A; i <= B; i++) {
        if (vc[i]) {
            string tmp = to_string(i);

            for (int j = 0; j < tmp.size(); j++) {
                if (tmp[j] == D) {
                    ans += 1;

                    break;
                }
            }
        }
    }

    cout << ans;

    return 0;
}