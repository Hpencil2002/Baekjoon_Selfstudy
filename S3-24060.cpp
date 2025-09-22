#include <iostream>
using namespace std;

int cnt = 0;

void merge(int A[], int p, int q, int r, int k) {
    int* tmp = new int[r + 2];
    int i = p;
    int j = q + 1;
    int t = 1;

    while (i <= q && j <= r) {
        if (A[i] <= A[j]) {
            tmp[t++] = A[i++];
        }
        else {
            tmp[t++] = A[j++];
        }
    }

    while (i <= q) {
        tmp[t++] = A[i++];
    }
    while (j <= r) {
        tmp[t++] = A[j++];
    }

    i = p;
    t = 1;

    while (i <= r) {
        A[i++] = tmp[t++];

        if (++cnt == k) {
            cout << tmp[t - 1];
        }
    }

    delete(tmp);
}

void merge_sort(int A[], int start, int end, int k) {
    int p = start;
    int r = end;

    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(A, p, q, k);
        merge_sort(A, q + 1, r, k);
        merge(A, p, q, r, k);
    }
}

int main() {
    int N, K;
    cin >> N >> K;

    int* A = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    merge_sort(A, 0, N - 1, K);

    if (cnt < K) {
        cout << -1;
    }

    return 0;
}