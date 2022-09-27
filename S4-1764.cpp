#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<string> not_hear(N);
    vector<string> result;

    for (int i = 0; i < N; i++) {
        cin >> not_hear[i];
    }

    sort(not_hear.begin(), not_hear.end());

    string not_see;
    for (int i = 0; i < M; i++) {
        cin >> not_see;
        if (binary_search(not_hear.begin(), not_hear.end(), not_see)) {
            result.push_back(not_see);
        }
    }
    sort(result.begin(), result.end());

    cout << result.size() << "\n";
    for (string name : result) {
        cout << name << "\n";
    }

    return 0;
}