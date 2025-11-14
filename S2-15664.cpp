#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N, M;
int first[9];
int arr[9];
bool visit[9];
set<vector<int>> st;

void dfs(int num, int k) {
    if (k == M) {
        vector<int> vc;
        for (int i = 0; i < M; i++) {
            vc.push_back(arr[i]);
        }
        st.insert(vc);
        vc.clear();
    }
    else {
        for (int i = num; i < N; i++) {
            if (!visit[i]) {
                visit[i] = true;
                arr[k] = first[i];
                dfs(i + 1, k + 1);
                visit[i] = false;
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> first[i];
    }

    sort(first, first + N);

    dfs(0, 0);

    for (auto vc : st) {
        for (auto num : vc) {
            cout << num << ' ';
        }
        cout << "\n";
    }

    return 0;
}