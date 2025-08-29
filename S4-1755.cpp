#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int M, N;
string str;
string nums[11] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
vector<pair<string, int>> vc;

int main() {
    cin >> M >> N;

    for (int i = M; i <= N; i++) {
        if (i >= 10) {
            str = nums[i / 10] + " " + nums[i % 10];
            vc.push_back({str, i});
        }
        else {
            str = nums[i % 10];
            vc.push_back({str, i});
        }
    }

    sort(vc.begin(), vc.end());

    for (int i = 0; i < vc.size(); i++) {
        cout << vc[i].second << ' ';
        if (i % 10 == 9) {
            cout << "\n";
        }
    }

    return 0;
}