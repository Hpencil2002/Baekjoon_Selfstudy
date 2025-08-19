#include <iostream>
#include <algorithm>
using namespace std;

int trees[100001];
int min_trees[100001];

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> trees[i];
    }

    sort(trees, trees + N, greater<int>());

    for (int i = 0; i < N; i++) {
        min_trees[i] = (i + 1) + trees[i];
    }

    sort(min_trees, min_trees + N, greater<int>());

    cout << min_trees[0] + 1;

    return 0;
}