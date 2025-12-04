#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int F, S, G, U, D;
int path[1000001];
bool visit[1000001];
vector<int> dx;
queue<int> qu;

void bfs(int v) {
    visit[v] = true;
    qu.push(v);

    while (!qu.empty()) {
        v = qu.front();
        qu.pop();

        for (int d = 0; d < 2; d++) {
            int v_next = v + dx[d];

            if (v_next > 0 && v_next <= F) {
                if (!visit[v_next]) {
                    visit[v_next] = true;
                    qu.push(v_next);
                    path[v_next] = path[v] + 1;
                }
            }
        }
    }
}

int main() {
    cin >> F >> S >> G >> U >> D;

    dx.push_back(U);
    dx.push_back(D * (-1));

    bfs(S);

    if (visit[G]) {
        cout << path[G];
    }
    else {
        cout << "use the stairs";
    }

    return 0;
}