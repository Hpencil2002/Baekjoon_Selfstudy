#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v1;
vector<int> v2;

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        int tmp;
        cin >> tmp;
        v1.insert(v1.begin() + (tmp - 1), i);
    }

    while (v1.size() > M) {
        v1.pop_back();
    }

    for (int i = 1; i <= M; i++) {
        int tmp;
        cin >> tmp;
        v2.insert(v2.begin() + (tmp - 1), v1.back());
        v1.pop_back();
    }

    while (v2.size() > 3) {
        v2.pop_back();
    }

    for (int i = 0; i < v2.size(); i++) {
        cout << v2[i] << "\n";
    }

    return 0;
}