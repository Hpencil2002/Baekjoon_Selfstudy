#include <iostream>
#include <algorithm>
using namespace std;

struct Egg
{
    int hp;
    int weight;
};

int N;
Egg egg[10];
int ans;

void solve(int x) {
    if (x > N + 1) {
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (egg[x].hp <= 0) {
            solve(x + 1);
        }
        else if (x == i || egg[i].hp <= 0) {
            continue;
        }
        else {
            egg[x].hp -= egg[i].weight;
            egg[i].hp -= egg[x].weight;

            solve(x + 1);

            egg[x].hp += egg[i].weight;
            egg[i].hp += egg[x].weight;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (egg[i].hp <= 0) {
            cnt += 1;
        }
    }

    ans = max(ans, cnt);
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int h, w;
        cin >> h >> w;

        egg[i] = { h, w };
    }

    solve(1);

    cout << ans;

    return 0;
}