#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n;
int arr[1000001];
vector<int> prime;

void getPrime() {
    arr[0] = -1;
    arr[1] = -1;
    for (int i = 2; i < 1000001; i++) {
        arr[i] = i;
    }

    for (int i = 2; i * i < 1000001; i++) {
        if (arr[i] == i) {
            for (int j = i * i; j < 1000001; j += i) {
                if (arr[j] == j) {
                    arr[j] = i;
                }
            }
        }
    }

    for (int i = 2; i < 1000001; i++) {
        if (arr[i] == i) {
            prime.push_back(i);
        }
    }
}

bool solve(int N) {
    map<int, bool> mp;
    int tmp = N;

    while (true) {
        int res = 0;

        while (tmp) {
            res += (tmp % 10) * (tmp % 10);
            tmp /= 10;
        }

        if (res == 1) {
            return true;
        }

        if (!mp.count(res)) {
            mp[res] = true;
        }
        else {
            return false;
        }

        tmp = res;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    getPrime();

    for (int i = 0; i < prime.size(); i++) {
        if (prime[i] > n) {
            break;
        }

        if (solve(prime[i])) {
            cout << prime[i] << "\n";
        }
    }

    return 0;
}