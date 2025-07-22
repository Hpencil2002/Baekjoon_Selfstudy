#include <iostream>
#include <vector>
using namespace std;

bool IsPrime(int a) {
    if (a == 2) {
        return false;
    }

    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int N;
    cin >> N;

    vector<int> vc;
    for (int i = 2; i <= 1000000; i++) {
        if (IsPrime(i)) {
            vc.push_back(i);
        }
    }

    long long m;
    for (int i = 0; i < N; i++) {
        cin >> m;

        bool flag = true;
        for (int j = 0; j < vc.size(); j++) {
            if (m % vc[j] == 0) {
                flag = false;
            }
        }

        if (flag) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}