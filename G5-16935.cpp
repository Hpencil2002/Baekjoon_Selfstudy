#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, R;
int arr[100][100];
int cArr[100][100];
vector<int> vc;

void copyArr(int a[][100], int b[][100]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = b[i][j];
        }
    }
}

void cmdOne() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cArr[N - i - 1][j] = arr[i][j];
        }
    }

    copyArr(arr, cArr);
}

void cmdTwo() {
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            cArr[i][M - 1 - j] = arr[i][j];
        }
    }

    copyArr(arr, cArr);
}

void cmdThree() {
    int n = N;
    swap(N, M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cArr[i][j] = arr[n - 1 - j][i];
        }
    }

    copyArr(arr, cArr);
}

void cmdFour() {
    int m = M;
    swap(N, M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cArr[i][j] = arr[j][m - 1 - i];
        }
    }

    copyArr(arr, cArr);
}

void cmdFive() {
    int halfN = N / 2;
    int halfM = M / 2;

    for (int i = 0; i < halfN; i++) {
        for (int j = 0; j < halfM; j++) {
            cArr[i][j + halfM] = arr[i][j];
        }
    }

    for (int i = 0; i < halfN; i++) {
        for (int j = halfM; j < M; j++) {
            cArr[i + halfN][j] = arr[i][j];
        }
    }

    for (int i = halfN; i < N; i++) {
        for (int j = halfM; j < M; j++) {
            cArr[i][j - halfM] = arr[i][j];
        }
    }

    for (int i = halfN; i < N; i++) {
        for (int j = 0; j < halfM; j++) {
            cArr[i - halfN][j] = arr[i][j];
        }
    }

    copyArr(arr, cArr);
}

void cmdSix() {
    int halfN = N / 2;
    int halfM = M / 2;

    for (int i = 0; i < halfN; i++) {
        for (int j = 0; j < halfM; j++) {
            cArr[i + halfN][j] = arr[i][j];
        }
    }

    for (int i = halfN; i < N; i++) {
        for (int j = 0; j < halfM; j++) {
            cArr[i][j + halfM] = arr[i][j];
        }
    }

    for (int i = halfN; i < N; i++) {
        for (int j = halfM; j < M; j++) {
            cArr[i - halfN][j] = arr[i][j];
        }
    }

    for (int i = 0; i < halfN; i++) {
        for (int j = halfM; j < M; j++) {
            cArr[i][j - halfM] = arr[i][j];
        }
    }

    copyArr(arr, cArr);
}

int main() {
    cin >> N >> M >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < R; i++) {
        int a;
        cin >> a;

        vc.push_back(a);
    }

    for (int i = 0; i < vc.size(); i++) {
        if (vc[i] == 1) {
            cmdOne();
        }
        else if (vc[i] == 2) {
            cmdTwo();
        }
        else if (vc[i] == 3) {
            cmdThree();
        }
        else if (vc[i] == 4) {
            cmdFour();
        }
        else if (vc[i] == 5) {
            cmdFive();
        }
        else {
            cmdSix();
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << arr[i][j] << ' ';
        }

        cout << "\n";
    }

    return 0;
}