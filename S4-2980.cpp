#include <iostream>
#include <vector>
using namespace std;

typedef struct {
    int D;
    int R;
    int G;
    int cycle;
} Signal_Lamp;

int N, L;
vector<Signal_Lamp> vc;

bool traffic_state(int index, int t) {
    if (t % vc[index].cycle <= vc[index].R) {
        return false;
    }
    else {
        return true;
    }
}

int main() {
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        Signal_Lamp S;
        int D, R, G;

        cin >> D >> R >> G;
        S.D = D;
        S.R = R;
        S.G = G;
        S.cycle = S.R + S.G;

        vc.push_back(S);
    }

    int distance = 0;
    int time = 0;
    int index = 0;

    while (true) {
        if (distance == L) {
            break;
        }

        if (index < vc.size()) {
            if (vc[index].D == distance) {
                if (traffic_state(index, time)) {
                    distance += 1;
                    time += 1;
                }
                else {
                    int tmp = time % vc[index].cycle;
                    time += vc[index].R - tmp;
                }

                index += 1;
                continue;
            }
        }

        distance += 1;
        time += 1;
    }

    cout << time;

    return 0;
}