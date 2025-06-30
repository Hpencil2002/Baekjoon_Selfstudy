#include <iostream>
#include <string>
using namespace std;

int x_move[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int y_move[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

int main() {
    int N;
    cin >> N;

    int arr[1001][1001];
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < str.size(); j++) {
            if (str[j] == '.') {
                arr[i][j] = 0;
            }
            else{
                arr[i][j] = str[j] - '0';
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] > 0) {
                cout << "*";
            }
            else {
                int cnt = 0;
                for (int k = 0; k < 8; k++) {
                    int x_next = i + x_move[k];
                    int y_next = j + y_move[k];

                    if (x_next < 0 || x_next >= N || y_next < 0 || y_next >= N) {
                        continue;
                    }
                    if (arr[x_next][y_next] > 0) {
                        cnt += arr[x_next][y_next];
                    }
                }

                if (cnt >= 10) {
                    cout << "M";
                }
                else {
                    cout << cnt;
                }
            }
        }

        cout << "\n";
    }

    return 0;
}