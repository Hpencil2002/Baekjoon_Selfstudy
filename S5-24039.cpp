#include <iostream>
#include <vector>
using namespace std;

vector<int> vc;
int check[10001];

void makePrime() {
    for (int i = 2; i * i <= 10000; i++) {
        if (check[i]) {
            continue;
        }

        for (int j = i + i; j <= 10000; j += i) {
            check[j] = 1;
        }
    }

    for (int i = 2; i <= 10000; i++) {
        if (!check[i]) {
            vc.push_back(i);
        }
    }
}

int main() {
    int N;
    cin >> N;

    makePrime();

    int ans;
    for (int i = 0; i < vc.size() - 1; i++) {
        int mul = vc[i] * vc[i + 1];

        if (mul > N) {
            ans = mul;
            break;
        }
    }

    cout << ans;

    return 0;
}