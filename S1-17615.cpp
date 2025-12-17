#include <iostream>
#include <string>
using namespace std;

int N, flag, red, blue;
int ans;
string str;

int main() {
    cin >> N >> str;

    int start_R = 0, start_B = 0;
    int end_R = 0, end_B = 0;
    if (str[0] == 'R') {
        red += 1;
        start_R += 1;
    }
    else {
        blue += 1;
        start_B += 1;
    }

    for (int i = 1; i < N; i++) {
        if (!flag) {
            if (str[i] == str[0] && start_R) {
                red += 1;
                start_R += 1;
            }
            else if (str[i] == str[0] && start_B) {
                blue += 1;
                start_B += 1;
            }
            else {
                if (str[i] == 'R') {
                    red += 1;
                    end_R += 1;
                }
                else {
                    blue += 1;
                    end_B += 1;
                }

                flag = 1;
            }
        }
        else {
            if (str[i] == 'R') {
                end_B = 0;
                red += 1;
                end_R += 1;
            }
            else {
                end_R = 0;
                blue += 1;
                end_B += 1;
            }
        }
    }

    ans = red - start_R;
    if (blue - start_B < ans) {
        ans = blue - start_B;
    }
    if (red - end_R < ans) {
        ans = red - end_R;
    }
    if (blue - end_B < ans) {
        ans = blue - end_B;
    }

    cout << ans;

    return 0;
}