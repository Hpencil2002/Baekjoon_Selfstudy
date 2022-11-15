#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b);

int main() {
    int N;
    string word;
    vector<string> v;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> word;
        if (find(v.begin(), v.end(), word) == v.end()) {
            v.push_back(word);
        }
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }

    return 0;
}

bool compare(string a, string b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    else {
        return a < b;
    }
}