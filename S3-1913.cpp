#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int N, num;
    cin >> N >> num;

    int x = 0;
    int y = 0;
    int row = -1;
    int col = 0;
    int dir = 1;
    int copy = N;
    int square = N * N;

    int** arr;
    arr = new int*[N];
    for (int i = 0; i < N; i++) {
        arr[i] = new int[N];
        memset(arr[i], 0, sizeof(int) * N);
    }

    while (square > 0) {
        for (int i = 0; i < copy; i++) {
            row += dir;
            arr[row][col] = square;

            if (square == num) {
                x = row + 1;
                y = col + 1;
            }

            square -= 1;
        }

        copy -= 1;

        for (int i = 0; i < copy; i++) {
            col += dir;
            arr[row][col] = square;

            if (square == num) {
                x = row + 1;
                y = col + 1;
            }

            square -= 1;
        }

        dir *= -1;
    }

    for (int i = 0; i < N * N; i++) {
        int r = i / N;
        int c = i % N;

        cout << arr[r][c] << ' ';

        if ((i % N) == N - 1) {
            cout << "\n";
        }
    }
    cout << x << ' ' << y;

    for (int i = 0; i < N; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}