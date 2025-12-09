#include <iostream>
#include <string>
using namespace std;

string S;
int q;
int cnt[27][200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S >> q;

    cnt[S[0] - 'a'][0] = 1;
    for (int i = 1; i < S.size(); i++) {
        for (int j = 0; j < 27; j++) {
            cnt[j][i] = cnt[j][i - 1];
        }

        cnt[S[i] - 'a'][i] += 1;
    }

    for (int i = 0; i < q; i++) {
        int start, end;
        char letter;

        cin >> letter >> start >> end;

        if (start == 0) {
            cout << cnt[letter - 'a'][end] << "\n";
        }
        else {
            cout << cnt[letter - 'a'][end] - cnt[letter - 'a'][start - 1] << "\n";
        }
    }

    return 0;
}