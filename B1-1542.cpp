#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<int> sejun;
        vector<int> sebi;
        for (int i = 0; i < N; i++) {
            int tmp;
            cin >> tmp;
            sejun.push_back(tmp);
        }
        for (int i = 0; i < M; i++) {
            int tmp;
            cin >> tmp;
            sebi.push_back(tmp);
        }

        sort(sejun.begin(), sejun.end());
        sort(sebi.begin(), sebi.end());

        while (true) {
            if (sejun[0] > sebi[0]) {
                sebi.erase(sebi.begin() + 0);
            }
            else if (sejun[0] < sebi[0]) {
                sejun.erase(sejun.begin() + 0);
            }
            else {
                int last_sejun = sejun.back();
                int last_sebi = sebi.back();

                if (last_sejun > last_sebi) {
                    sebi.erase(sebi.begin() + 0);
                }
                else if (last_sejun < last_sebi) {
                    sejun.erase(sejun.begin() + 0);
                }
                else {
                    sebi.erase(sebi.begin() + 0);
                }
            }

            if (sejun.size() == 0) {
                cout << "B\n";
                break;
            }
            if (sebi.size() == 0) {
                cout << "S\n";
                break;
            }
        }
    }

    return 0;
}