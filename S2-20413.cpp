#include <iostream>
#include <string>
using namespace std;

int N;
int b, s, g, p, d;
int pay[36];
char mvp;
int ans;

int solve(int index, char c) {
    if (index == 0) {
        if (c == 'B') {
            return s - 1;
        }
        else if (c == 'S') {
            return g - 1;
        }
        else if (c == 'G') {
            return p - 1;
        }
        else if (c == 'P') {
            return d - 1;
        }
        else if (c == 'D') {
            return d;
        }
    }
    else {
        int prev = pay[index - 1];

        if (c == 'B') {
            return s - 1 - prev;
        }
        else if (c == 'S') {
            return g - 1 - prev;
        }
        else if (c == 'G') {
            return p - 1 - prev;
        }
        else if (c == 'P') {
            return d - 1 - prev;
        }
        else if (c == 'D') {
            return d;
        }
    }
}

int main() {
    cin >> N;
    cin >> s >> g >> p >> d;
    for (int i = 0; i < N; i++) {
        cin >> mvp;

        pay[i] = solve(i, mvp);
        ans += pay[i];
    }

    cout << ans;

    return 0;
}