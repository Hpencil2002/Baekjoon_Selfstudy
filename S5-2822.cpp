#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int input[8] = { 0, };
    vector<int> score;

    for (int i = 0; i < 8; i++) {
        cin >> input[i];
        score.push_back(input[i]);
    }

    sort(input, input + 8, greater<int>());

    int ans = 0;
    int index[5] = { 0, };

    for (int i = 0; i < 5; i++) {
        ans += input[i];

        int tmp = find(score.begin(), score.end(), input[i]) - score.begin();
        index[i] = tmp + 1;
    }

    cout << ans << "\n";

    sort(index, index + 5);
    for (int i = 0; i < 5; i++) {
        cout << index[i] << ' ';
    }

    return 0;
}