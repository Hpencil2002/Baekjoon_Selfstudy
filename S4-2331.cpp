#include <iostream>
#include <cmath>
using namespace std;

int visit[236916];
int P;
int ans;

void DFS(int A) {
    int origin = A;
    int next = 0;

    visit[A - 1] += 1;

    while (A > 0) {
        next += (int)pow(A % 10, P);
        A /= 10;
    }

    if (visit[next - 1] == 2) {
        return;
    }

    DFS(next);

    if (visit[origin - 1] == 1) {
        ans += 1;
    }
}

int main() {
    int A;
    cin >> A >> P;

    DFS(A);

    cout << ans;

    return 0;
}