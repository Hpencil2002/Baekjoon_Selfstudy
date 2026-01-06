#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int R, C;
char arr[21][21];
vector<string> vc;

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }

    string buff = "";

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] == '#') {
                if (buff.size() > 1) {
                    vc.push_back(buff);
                }
                buff.clear();

                continue;
            }

            buff += arr[i][j];
        }

        if (buff.size() > 1) {
            vc.push_back(buff);
        }
        buff.clear();
    }

    for (int i = 0; i < C; i++) {
        for (int j = 0; j < R; j++) {
            if (arr[j][i] == '#') {
                if (buff.size() > 1) {
                    vc.push_back(buff);
                }
                buff.clear();

                continue;
            }

            buff += arr[j][i];
        }

        if (buff.size() > 1) {
            vc.push_back(buff);
        }
        buff.clear();
    }

    sort(vc.begin(), vc.end());

    cout << vc.front();

    return 0;
}