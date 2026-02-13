#include <iostream>
#include <vector>
#include <string>
using namespace std;

int K;
vector<int> wheel[4];
vector<pair<int, int>> order;
int ans;

int reverseDirection(int d) {
    if (d == 1) {
        return -1;
    }
    else {
        return 1;
    }
}

void actualTurn(int n, int d) {
    if (d == 1) {
        int tmp = wheel[n].at(7);

        for (int i = 7; i > 0; i--) {
            wheel[n].at(i) = wheel[n].at(i - 1);
        }

        wheel[n].at(0) = tmp;
    }
    else if (d == -1) {
        int tmp = wheel[n].at(0);

        for (int i = 0; i < 7; i++) {
            wheel[n].at(i) = wheel[n].at(i + 1);
        }

        wheel[n].at(7) = tmp;
    }
}

void turnWheel(int n, int d) {
    int nd = reverseDirection(d);

    if (n == 0) {
        if (wheel[n].at(2) != wheel[n + 1].at(6)) {
            if (wheel[n + 1].at(2) != wheel[n + 2].at(6)) {
                if (wheel[n + 2].at(2) != wheel[n + 3].at(6)) {
                    actualTurn(n, d);
                    actualTurn(n + 1, nd);
                    actualTurn(n + 2, d);
                    actualTurn(n + 3, nd);
                }
                else {
                    actualTurn(n, d);
                    actualTurn(n + 1, nd);
                    actualTurn(n + 2, d);
                }
            }
            else {
                actualTurn(n, d);
                actualTurn(n + 1, nd);
            }
        }
        else {
            actualTurn(n, d);
        }
    }
    else if (n == 1) {
        if (wheel[n].at(6) != wheel[n - 1].at(2)) {
            actualTurn(n - 1, nd);
        }

        if (wheel[n].at(2) != wheel[n + 1].at(6)) {
            if (wheel[n + 1].at(2) != wheel[n + 2].at(6)) {
                actualTurn(n, d);
                actualTurn(n + 1, nd);
                actualTurn(n + 2, d);
            }
            else {
                actualTurn(n, d);
                actualTurn(n + 1, nd);
            }
        }
        else {
            actualTurn(n, d);
        }
    }
    else if (n == 2) {
        if (wheel[n].at(2) != wheel[n + 1].at(6)) {
            actualTurn(n + 1, nd);
        }

        if (wheel[n].at(6) != wheel[n - 1].at(2)) {
            if (wheel[n - 1].at(6) != wheel[n - 2].at(2)) {
                actualTurn(n, d);
                actualTurn(n - 1, nd);
                actualTurn(n - 2, d);
            }
            else {
                actualTurn(n, d);
                actualTurn(n - 1, nd);
            }
        }
        else {
            actualTurn(n, d);
        }
    }
    else if (n == 3) {
        if (wheel[n].at(6) != wheel[n - 1].at(2)) {
            if (wheel[n - 1].at(6) != wheel[n - 2].at(2)) {
                if (wheel[n - 2].at(6) != wheel[n - 3].at(2)) {
                    actualTurn(n, d);
                    actualTurn(n - 1, nd);
                    actualTurn(n - 2, d);
                    actualTurn(n - 3, nd);
                }
                else {
                    actualTurn(n, d);
                    actualTurn(n - 1, nd);
                    actualTurn(n - 2, d);
                }
            }
            else {
                actualTurn(n, d);
                actualTurn(n - 1, nd);
            }
        }
        else {
            actualTurn(n, d);
        }
    }
}

int main() {
    for (int i = 0; i < 4; i++) {
        string input;
        cin >> input;

        for (int j = 0; j < input.length(); j++) {
            wheel[i].push_back(input[j] - '0');
        }
    }

    cin >> K;
    for (int i = 0; i < K; i++) {
        int num, dir;
        cin >> num >> dir;

        order.push_back({ num - 1, dir });
    }

    for (int i = 0; i < order.size(); i++) {
        int N = order[i].first;
        int D = order[i].second;

        turnWheel(N, D);
    }

    if (wheel[0].at(0) == 1) {
        ans += 1;
    }
    if (wheel[1].at(0) == 1) {
        ans += 2;
    }
    if (wheel[2].at(0) == 1) {
        ans += 4;
    }
    if (wheel[3].at(0) == 1) {
        ans += 8;
    }

    cout << ans;

    return 0;
}