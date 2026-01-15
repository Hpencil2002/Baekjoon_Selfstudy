#include <iostream>
#include <vector>
using namespace std;

int T;
int k;
int check[1300001];
vector<int> prime;

void Init() {
    for (int i = 2; i <= 1300000; i++) {
        if (check[i]) {
            continue;
        }

        for (int j = i + i; j <= 1300000; j += i) {
            check[j] = 1;
        }
    }

    for (int i = 2; i <= 1300000; i++) {
        if (!check[i]) {
            prime.push_back(i);
        }
    }
}

int solve(int key) {
    int start = 2;
    int end = prime.size() - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (prime[mid] >= key) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    return start;
}

int main() {
    cin >> T;
    Init();

    while (T--) {
        cin >> k;

        if (!check[k]) {
            cout << "0\n";
        }
        else {
            int index = solve(k);
            cout << prime[index] - prime[index - 1] << "\n";
        }
    }

    return 0;
}