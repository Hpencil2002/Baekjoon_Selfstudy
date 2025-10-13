#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mat[1024][1024];

int DC(int half, int x, int y) {
    vector<int> vc;

    if (half == 1) {
        vc.push_back(mat[y][x]);
        vc.push_back(mat[y][x + 1]);
        vc.push_back(mat[y + 1][x]);
        vc.push_back(mat[y + 1][x + 1]);

        sort(vc.begin(), vc.end());

        return vc[2];
    }
    else {
        vc.push_back(DC(half / 2, x, y));
        vc.push_back(DC(half / 2, x + half, y));
        vc.push_back(DC(half / 2, x, y + half));
        vc.push_back(DC(half / 2, x + half, y + half));

        sort(vc.begin(), vc.end());

        return vc[2];
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
        }
    }

    cout << DC(N / 2, 0, 0);

    return 0;
}