#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        map<int, int> mp;

        cin >> N;
        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            mp[num] = 1;
        }

        cin >> M;
        for (int i = 0; i < M; i++) {
            int num;
            cin >> num;

            if (mp[num] == 1) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
    }

    return 0;
}