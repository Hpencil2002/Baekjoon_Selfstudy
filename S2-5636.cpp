#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

string num;
bool isPrime[100001];
vector<int> prime;

void init() {
    memset(isPrime, true, sizeof(isPrime));

    isPrime[0] = false;
    isPrime[1] = false;
    for (long long i = 2; i < 100001; i++) {
        if (isPrime[i]) {
            prime.push_back(i);

            for (long long j = i * i; j < 100001; j += i) {
                isPrime[j] = false;
            }
        }
    }

    sort(prime.begin(), prime.end(), greater<int>());
}

int main() {
    init();

    while (true) {
        cin >> num;
        if (num == "0") {
            return 0;
        }

        for (int i = 0; i < prime.size(); i++) {
            if (num.find(to_string(prime[i])) != string::npos) {
                cout << prime[i] << "\n";

                break;
            }
        }
    }
}