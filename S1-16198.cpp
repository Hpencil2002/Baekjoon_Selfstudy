#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> vc;
int ans, tmp;

void select_ball() {
    if (vc.size() == 2) {
        if (ans < tmp) {
            ans = tmp;
        }

        return;
    }

    for (int i = 1; i < vc.size() - 1; i++) {
        int select = vc.at(i);
        tmp += vc.at(i - 1) * vc.at(i + 1);

        vc.erase(vc.begin() + i);
        select_ball();
        vc.insert(vc.begin() + i, select);

        tmp -= vc.at(i - 1) * vc.at(i + 1);
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        vc.push_back(a);
    }

    select_ball();

    cout << ans;

    return 0;
}