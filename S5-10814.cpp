#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, string> a, pair<int, string> b);

int main() {
    int N;
    pair<int, string> pr;
    vector<pair<int, string>> vc;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int age;
        string name;
        cin >> age >> name;

        pr.first = age, pr.second = name;
        vc.push_back(pr);
    }

    stable_sort(vc.begin(), vc.end(), comp);

    for (int i = 0; i < N; i++) {
        cout << vc[i].first << " " << vc[i].second << "\n";
    }

    return 0;
}

bool comp(pair<int, string> a, pair<int, string> b) {
    return a.first < b.first;
}