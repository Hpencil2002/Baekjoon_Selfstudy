#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    int N, M;
    string site, pw;
    unordered_map<string, string> um;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> site >> pw;
        um[site] = pw;
    }

    for (int i = 0; i < M; i++) {
        string tmp;
        cin >> tmp;
        cout << um[tmp] << "\n";
    }

    return 0;
}