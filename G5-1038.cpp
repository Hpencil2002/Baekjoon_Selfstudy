#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<long long> vc;
queue<long long> qu;

int main() {
    cin >> N;

    for (int i = 0; i <= 9; i++) {
        qu.push(i);
        vc.push_back(i);
    }

    while (!qu.empty()) {
        long long num = qu.front();
        int last = num % 10;
        qu.pop();

        for (int i = 0; i < last; i++) {
            long long newNum = num * 10 + i;
            qu.push(newNum);
            vc.push_back(newNum);
        }
    }

    if (N >= vc.size()) {
        cout << -1;
    }
    else {
        cout << vc[N];
    }

    return 0;
}