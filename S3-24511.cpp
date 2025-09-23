#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    bool flag[100001];
    for (int i = 0; i < N; i++) {
        cin >> flag[i];
    }

    deque<int> dq;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if (!flag[i]) {
            dq.push_back(num);
        }
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;

        dq.push_front(num);
        cout << dq.back() << ' ';
        dq.pop_back();
    }

    return 0;
}