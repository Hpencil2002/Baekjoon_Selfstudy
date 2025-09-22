#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

typedef struct {
    int number;
    int strike;
    int ball;
} Game;

int N;
int ans;
bool ableNumber[1000];
vector<Game> vc;

int main() {
    cin >> N;

    memset(ableNumber, true, sizeof(ableNumber));
    for (int i = 123; i <= 999; i++) {
        string tmp = to_string(i);
        if (tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2]) {
            ableNumber[i] = false;
        }
        if (tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0') {
            ableNumber[i] = false;
        }
    }

    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        Game G;
        G.number = a;
        G.strike = b;
        G.ball = c;

        vc.push_back(G);
    }

    for (int i = 0; i < vc.size(); i++) {
        int num = vc[i].number;
        int strike = vc[i].strike;
        int ball = vc[i].ball;
        string origin = to_string(num);

        for (int j = 123; j <= 999; j++) {
            int tmp_strike = 0;
            int tmp_ball = 0;

            if (ableNumber[j]) {
                string tmp = to_string(j);
                for (int a = 0; a < 3; a++) {
                    for (int b = 0; b < 3; b++) {
                        if (a == b && origin[a] == tmp[b]) {
                            tmp_strike += 1;
                        }
                        if (a != b && origin[a] == tmp[b]) {
                            tmp_ball += 1;
                        }
                    }
                }

                if (strike != tmp_strike || ball != tmp_ball) {
                    ableNumber[j] = false;
                }
            }
        }
    }

    for (int i = 123; i <= 999; i++) {
        if (ableNumber[i]) {
            ans += 1;
        }
    }

    cout << ans;

    return 0;
}