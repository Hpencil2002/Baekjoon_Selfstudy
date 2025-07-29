#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct candidate {
    int num = 0;
    int score[4] = {};

    bool same = false;
};

bool comp(candidate& a, candidate& b) {
    if (a.score[0] == b.score[0]) {
        if (a.score[3] == b.score[3]) {
            if (a.score[2] == b.score[2]) {
                if (a.score[1] == b.score[1]) {
                    a.same = true;
                    b.same = true;

                    return a.score[1] < b.score[1];
                }
                else {
                    return a.score[1] < b.score[1];
                }
            }
            else {
                return a.score[2] < b.score[2];
            }
        }
        else {
            return a.score[3] < b.score[3];
        }
    }
    else {
        return a.score[0] < b.score[0];
    }
}

int main() {
    int N;
    cin >> N;

    vector<candidate> vc;
    for (int i = 0; i < 3; i++) {
        candidate c;
        c.num = i + 1;
        vc.push_back(c);
    }

    while (N--) {
        int vote[3];
        cin >> vote[0] >> vote[1] >> vote[2];

        for (int i = 0; i < 3; i++) {
            vc[i].score[0] += vote[i];
            vc[i].score[vote[i]] += 1;
        }
    }

    sort(vc.begin(), vc.end(), comp);

    if (vc[2].same != 1) {
        cout << vc[2].num << ' ' << vc[2].score[0];
    }
    else {
        cout << 0 << ' ' << vc[2].score[0];
    }

    return 0;
}