#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int yeondo_L, yeondo_O, yeondo_V, yeondo_E;

bool comp(pair<string, int> a, pair<string, int> b) {
    if (a.second != b.second) {
        return a.second > b.second;
    }
    else {
        return a.first < b.first;
    }
}

int main() {
    string yeondo;
    cin >> yeondo;

    for (int i = 0; i < yeondo.size(); i++) {
        if (yeondo[i] == 'L') {
            yeondo_L += 1;
        }
        else if (yeondo[i] == 'O') {
            yeondo_O += 1;
        }
        else if (yeondo[i] == 'V') {
            yeondo_V += 1;
        }
        else if (yeondo[i] == 'E') {
            yeondo_E += 1;
        }
    }

    int N;
    vector<pair<string, int>> vc;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string team;
        cin >> team;

        int L = yeondo_L;
        int O = yeondo_O;
        int V = yeondo_V;
        int E = yeondo_E;

        for (int j = 0; j < team.size(); j++) {
            if (team[j] == 'L') {
                L += 1;
            }
            else if (team[j] == 'O') {
                O += 1;
            }
            else if (team[j] == 'V') {
                V += 1;
            }
            else if (team[j] == 'E') {
                E += 1;
            }
        }

        int win = ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;
        vc.push_back({team, win});
    }

    sort(vc.begin(), vc.end(), comp);

    cout << vc[0].first;

    return 0;
}