#include <iostream>
#include <stack>
using namespace std;

int ans;
stack<int> score;
stack<int> remain_time;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if (num == 1) {
            int A, T;
            cin >> A >> T;

            score.push(A);
            remain_time.push(T);
        }

        if (!remain_time.empty()) {
            remain_time.top() -= 1;

            if (remain_time.top() == 0) {
                ans += score.top();
                score.pop();
                remain_time.pop();
            }
        }
    }

    cout << ans;

    return 0;
}