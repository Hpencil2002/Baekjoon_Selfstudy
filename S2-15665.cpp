#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[8];
bool visit[8];
vector<int> vc;

void dfs(int start) {
    if (start == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << "\n";
    }
    else {
        for (int i = 1; i <= vc.size() - 1; i++) {
            arr[start] = vc[i - 1];
            dfs(start + 1);
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        vc.push_back(num);
    }

    sort(vc.begin(), vc.end());

    vc.erase(unique(vc.begin(), vc.end()), vc.end() - 1);

    dfs(0);

    return 0;
}