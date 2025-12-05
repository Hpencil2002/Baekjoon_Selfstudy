#include <iostream>
using namespace std;

char arr_A[50][50];
char arr_B[50][50];

void change(char arr[][50], int y, int x) {
    for (int i = y; i < y + 3; i++) {
        for (int j = x; j < x + 3; j++) {
            if (arr[i][j] == '1') {
                arr[i][j] = '0';
            }
            else if (arr[i][j] == '0') {
                arr[i][j] = '1';
            }
        }
    }
}

int solve(int N, int M) {
    int ans = 0;

    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 2; j++) {
            if (arr_A[i][j] != arr_B[i][j]) {
                change(arr_A, i, j);
                ans += 1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr_A[i][j] != arr_B[i][j]) {
                return -1;
            }
        }
    }

    return ans;
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char num;
            cin >> num;
            arr_A[i][j] = num;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char num;
            cin >> num;
            arr_B[i][j] = num;
        }
    }

    cout << solve(N, M);

    return 0;
}