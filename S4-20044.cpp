#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> student(n * 2);
    for (int i = 0; i < n * 2; i++) {
        cin >> student[i];
    }

    sort(student.begin(), student.end());

    int current = 0;
    int ans = student[0] + student[n * 2 - 1];
    for (int i = 0; i < n * 2; i++) {
        current = student[i] + student[n * 2 - i - 1];
        if (current < ans) {
            ans = current;
        }
    }

    cout << ans;

    return 0;
}