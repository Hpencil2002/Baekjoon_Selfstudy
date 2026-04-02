#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> mines;
bool visit[50001];

void explode(int index) {
    visit[index] = true;

    if (index - 1 >= 0) {
        if (mines[index] > mines[index - 1] && !visit[index - 1]) {
            return explode(index - 1);
        }
    }
    if (index + 1 < N) {
        if (mines[index] > mines[index + 1] && !visit[index + 1]) {
            return explode(index + 1);
        }
    }
}

void solve() {
    if (mines.size() == 1) {
        cout << "1\n";

        return;
    }

    for (int i = 0; i < N; i++) {
        if (i == 0) {
            if (mines[i] >= mines[i + 1]) {
                cout << i + 1 << "\n";
                explode(i);
            }
        }
        else if (i == N - 1) {
            if (mines[i] >= mines[i - 1]) {
                cout << i + 1 << "\n";
                explode(i);
            }
        }
        else {
            if (mines[i] >= mines[i - 1] && mines[i] >= mines[i + 1]) {
                cout << i + 1 << "\n";
                explode(i);
            }
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int m;
        cin >> m;

        mines.push_back(m);
    }

    solve();

    return 0;
}