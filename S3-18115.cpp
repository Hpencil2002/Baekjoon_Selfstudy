#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> vc = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    deque<int> dq;
    int card = 1;
    for (int i = N - 1; i >= 0; i--) {
        if (vc[i] == 1) {
            dq.push_back(card);
        }
        else if (vc[i] == 2) {
            int tmp = dq.back();
            dq.pop_back();
            dq.push_back(card);
            dq.push_back(tmp);
        }
        else if (vc[i] == 3) {
            dq.push_front(card);
        }

        card += 1;
    }

    for (int i = N - 1; i >= 0; i--) {
        cout << dq[i] << ' ';
    }

    return 0;
}