#include <iostream>
#include <algorithm>
using namespace std;

bool ps();

int main() {
    long long N, M, max = -1;
    long long start, end, mid, sum;
    int *tree;

    cin >> N >> M;
    tree = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> tree[i];
    }
    sort(tree, tree + N);

    start = 0;
    end = tree[N - 1];

    while (start <= end) {
        sum = 0;
        mid = (start + end) / 2;

        for (int i = 0; i < N; i++) {
            if (tree[i] - mid > 0) {
                sum += tree[i] - mid;
            }
        }

        if (sum >= M) {
            start = mid + 1;
            if (mid > max) {
                max = mid;
            }
        }
        else {
            end = mid - 1;
        }
    }

    cout << max << "\n";

    return 0;
}