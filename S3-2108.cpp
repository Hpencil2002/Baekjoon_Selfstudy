#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int tmp[8001] = {0,};

int main() {
    int n;
    int *num;
    cin >> n;
    num = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    double tmp1 = 0;
    for (int i = 0; i < n; i++) {
        tmp1 += (double)num[i];
    }
    int tmp2 = round(tmp1 / n);
    cout << tmp2 << "\n";

    sort(num, num + n);
    cout << num[(n- 1) / 2] << "\n";

    for (int i = 0; i < n; i++) {
        tmp[num[i] + 4000] += 1;
    }
    int maxi = -1;
    for (int i = 0; i < 8001; i++) {
        if (tmp[i] > maxi) {
            maxi = tmp[i];
        }
    }
    vector<int> vc;
    for (int i = 0; i < 8001; i++) {
        if (tmp[i] == maxi) {
            vc.push_back(i - 4000);
        }
    }
    sort(vc.begin(), vc.end());
    if (vc.size() == 1) {
        cout << vc[0] << "\n";
    }
    else {
        cout << vc[1] << "\n";
    }

    int max = -4001, min = 4001;
    for (int i = 0; i < n; i++) {
        if (num[i] > max) {
            max = num[i];
        }
        if (num[i] < min) {
            min = num[i];
        }
    }
    cout << max - min << "\n";

    return 0;
}