#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int x_move[4] = { 0, 1, 0, -1 };
int y_move[4] = { -1, 0, 1, 0 };

int main() {
    int T;
    cin >> T;

    while (T--) {
        string str;
        cin >> str;

        int x = 0, y = 0, move = 0, minX = 0, maxX = 0, minY = 0, maxY = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == 'L' || str[i] == 'R') {
                if (str[i] == 'L') {
                    move = (move + 3) % 4;
                }
                else {
                    move = (move + 1) % 4;
                }
            }
            else {
                if (str[i] == 'F') {
                    x += x_move[move];
                    y += y_move[move];
                }
                else {
                    x -= x_move[move];
                    y -= y_move[move];
                }

                minX = min(x, minX);
                maxX = max(x, maxX);
                minY = min(y, minY);
                maxY = max(y, maxY);
            }
        }

        cout << (maxX - minX) * (maxY - minY) << "\n";
    }

    return 0;
}