#include <iostream>
using namespace std;

int find_parent(int parent[], int x) {
    if (x != parent[x]) {
        return parent[x] = find_parent(parent, parent[x]);
    }
    else {
        return parent[x];
    }
}

void merge(int parent[], int x, int y) {
    int px = find_parent(parent, parent[x]);
    int py = find_parent(parent, parent[y]);

    if (px != py) {
        if (px < py) {
            parent[py] = parent[px];
        }
        else {
            parent[px] = parent[py];
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    int know_cnt;
    cin >> know_cnt;

    int parent[53];

    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    int tmp;
    for (int i = 0; i < know_cnt; i++) {
        cin >> tmp;
        parent[tmp] = 0;
    }

    int pnum;
    int tmp2;

    int arr[53][53];
    int arrsize[53];
    for (int i = 0; i < M; i++) {
        cin >> pnum;
        cin >> tmp;
        arrsize[i] = pnum;
        arr[i][0] = tmp;

        for (int j = 1; j < pnum; j++) {
            cin >> tmp2;
            arr[i][j] = tmp2;
            merge(parent, tmp, tmp2);
        }
    }

    int ans = M;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < arrsize[i]; j++) {
            if (find_parent(parent, parent[arr[i][j]]) == 0) {
                ans -= 1;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}