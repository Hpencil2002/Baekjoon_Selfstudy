#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

priority_queue<int, vector<int>, less<int>> max_pq;
priority_queue<int, vector<int>, greater<int>> min_pq;
map<int ,int> mp;

int main() {
    int T;

    cin >> T;
    for (int i = 0; i < T; i++) {
        while (!max_pq.empty()) {
            max_pq.pop();
        }
        while (!min_pq.empty()) {
            min_pq.pop();
        }
        mp.clear();

        int k;

        cin >> k;
        for (int j = 0; j < k; j++) {
            char oper;
            int n;

            cin >> oper >> n;
            if (oper == 'I') {
                max_pq.push(n);
                min_pq.push(n);
                mp[n] += 1;
            }
            else {
                if (n == 1) {
                    if (!max_pq.empty()) {
                        mp[max_pq.top()] -= 1;
                        max_pq.pop();
                    }
                }
                else {
                    if (!min_pq.empty()) {
                        mp[min_pq.top()] -= 1;
                        min_pq.pop();
                    }
                }

                while (!min_pq.empty() && mp[min_pq.top()] == 0) {
                    min_pq.pop();
                }
                while (!max_pq.empty() && mp[max_pq.top()] == 0) {
                    max_pq.pop();
                }
            }
        }

        while (!min_pq.empty() && mp[min_pq.top()] == 0) {
            min_pq.pop();
        }
        while (!max_pq.empty() && mp[max_pq.top()] == 0) {
            max_pq.pop();
        }

        if (max_pq.empty() || min_pq.empty()) {
            cout << "EMPTY\n";
        }
        else {
            cout << max_pq.top() << ' ' << min_pq.top() << "\n";
        }
    }

    return 0;
}