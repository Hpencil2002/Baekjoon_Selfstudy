#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    string ques;
    unordered_map<string, int> hm;
    string pokemon[100000];

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> pokemon[i];
        hm[pokemon[i]] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> ques;

        if (isdigit(ques[0])) {
            int num = stoi(ques) - 1;
            cout << pokemon[num] << "\n";
        }
        else {
            auto index = hm.find(ques);
            cout << index->second + 1 << "\n";
        }
    }

    return 0;
}