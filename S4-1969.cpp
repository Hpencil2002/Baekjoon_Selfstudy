#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, answer = 0;
    cin >> N >> M;

    vector<string> vc;
    vector<int> sum(4, 0);
    vector<char> DNA;
    string ans = "";

    DNA.push_back('A');
    DNA.push_back('C');
    DNA.push_back('G');
    DNA.push_back('T');

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        vc.push_back(str);
    }

    for (int i = 0; i < M; i++) {
        int cnt = 0;
        int index = 0;

        for (int j = 0; j < N; j++) {
            if (vc[j][i] == 'A') {
                sum[0] += 1;
            }
            else if (vc[j][i] == 'C') {
                sum[1] += 1;
            }
            else if (vc[j][i] == 'G') {
                sum[2] += 1;
            }
            else if (vc[j][i] == 'T') {
                sum[3] += 1;
            }
        }

        for (int j = 0; j < 4; j++) {
            if (cnt < sum[j]) {
                cnt = sum[j];
                index = j;
            }
            else if (cnt == sum[j]) {
                continue;
            }
        }

        ans += DNA[index];
        sum.assign(4, 0);
    }

    cout << ans << "\n";

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (ans[j] != vc[i][j]) {
                answer += 1;
            }
        }
    }
    cout << answer;

    return 0;
}