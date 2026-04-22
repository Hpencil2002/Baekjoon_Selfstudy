#include <iostream>
#include <string>
#include <map>
using namespace std;

int N, P;
int W, L, G;
int score;
map<string, int> mp;

int main() {
    cin >> N >> P;
    cin >> W >> L >> G;

    for (int i = 0; i < P; i++) {
        string name, res;
        cin >> name >> res;

        if (res == "W") {
            mp[name] = W;
        }
        else {
            mp[name] = -L;
        }
    }

    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;

        if (score >= G) {
            break;
        }
        if (score < 0) {
            score = 0;
        }

        if (mp.find(name) != mp.end()) {
            score += mp[name];
        }
        else {
            score -= L;
        }
    }

    if (score >= G) {
        cout << "I AM NOT IRONMAN!!";
    }
    else {
        cout << "I AM IRONMAN!!";
    }

    return 0;
}