#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> vc;
    for (int i = 0; i < 14; i++) {
        int tmp;
        cin >> tmp;
        vc.push_back(tmp);
    }

    int jun = 0;
    int sung = 0;
    int _N = N;

    for (int i = 0; i < vc.size(); i++) {
        if (vc[i] <= _N) {
            jun = _N / vc[i];
            _N %= vc[i];
            break;
        }
    }
    jun = _N + (jun * vc[13]);

    int cnt = 0;
    int buy_index = 1e9;
    for (int i = 1; i < vc.size(); i++) {
        if (vc[i] < vc[i - 1]) {
            cnt += 1;
        }
        else {
            cnt = 0;
        }

        if (cnt >= 3) {
            if (vc[i] <= N) {
                sung += N / vc[i];
                N %= vc[i];
                buy_index = i;
            }
        }
    }

    cnt = 0;
    bool flag = false;
    for (int i = buy_index + 1; i < vc.size(); i++) {
        if (vc[i] > vc[i - 1]) {
            cnt += 1;
        }
        else {
            cnt = 0;
        }

        if (cnt >= 3) {
            flag = true;
            sung *= vc[i];
            break;
        }
    }

    if (!flag) {
        sung = N + (sung * vc[13]);
    }

    if (sung > jun) {
        cout << "TIMING";
    }
    else if (sung < jun) {
        cout << "BNP";
    }
    else {
        cout << "SAMESAME";
    }

    return 0;
}