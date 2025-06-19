#include <iostream>
using namespace std;

int N;
int kim, lim;
int ans = 0;

int main() {
    cin >> N >> kim >> lim;

    while (kim != lim) {
        kim = (kim + 1) / 2;
        lim = (lim + 1) / 2;
        ans += 1;
    }

    cout << ans;

    return 0;
}