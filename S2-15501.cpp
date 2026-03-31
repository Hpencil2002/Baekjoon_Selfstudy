#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> vc;
vector<int> check;

bool solve() {
    int index = 0;

    while (true) {
        if (vc[0] == check[index]) {
            break;
        }

        index += 1;
    }

    if (vc[1] == check[(index + 1) % n]) {
        for (int i = 2; i < n; i++) {
            if (vc[i] != check[(index + i) % n]) {
                return false;
            }
        }

        return true;
    }
    else if (vc[n - 1] == check[(index + 1) % n]) {
        for (int i = 2; i < n; i++) {
            if (vc[n - i] != check[(index + i) % n]) {
                return false;
            }
        }

        return true;
    }
    else {
        return false;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        vc.push_back(num);
    }
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        check.push_back(num);
    }

    cout << (solve() ? "good puzzle" : "bad puzzle");

    return 0;
}