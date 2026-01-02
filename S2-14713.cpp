#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

int N;
vector<queue<string>> vc;

int main() {
    cin >> N;
    vc = vector<queue<string>>(N + 1);

    string tmp;
    getline(cin, tmp);
    for (int i = 0; i < N + 1; i++) {
        getline(cin, tmp);

        istringstream ss(tmp);
        string buff;
        while (getline(ss, buff, ' ')) {
            vc[i].push(buff);
        }
    }

    bool check = false;
    int qu_size = vc[N].size();
    for (int i = 0; i < qu_size; i++) {
        string base = vc[N].front();

        for (int j = 0; j < N; j++) {
            if (!vc[j].empty() && vc[j].front() == base) {
                vc[j].pop();
                vc[N].pop();
                check = true;

                break;
            }
        }

        if (!check) {
            cout << "Impossible";

            return 0;
        }
        else {
            check = false;
        }
    }

    for (int i = 0; i < N; i++) {
        if (!vc[i].empty()) {
            cout << "Impossible";

            return 0;
        }
    }

    cout << "Possible";

    return 0;
}