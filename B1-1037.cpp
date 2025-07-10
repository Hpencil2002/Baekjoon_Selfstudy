#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int num;
    cin >> num;

    vector<int> vc;
    for (int i = 0; i < num; i++) {
        int tmp;
        cin >> tmp;
        vc.push_back(tmp);
    }

    sort(vc.begin(), vc.end());

    int ans;
    if (num > 1) {
        ans = vc.front() * vc.back();
    }
    else {
        ans = vc.front() * vc.front();
    }

    cout << ans;

    return 0;
}