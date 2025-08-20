#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct STUDENT {
    string name;
    int korean;
    int english;
    int math;
};

bool comp(STUDENT a, STUDENT b) {
    if (a.korean == b.korean && a.english == b.english && a.math == b.math) {
        return a.name < b.name;
    }
    else if (a.korean == b.korean && a.english == b.english) {
        return a.math > b.math;
    }
    else if (a.korean == b.korean) {
        return a.english < b.english;
    }
    else {
        return a.korean > b.korean;
    }
}

int main() {
    int N;
    cin >> N;

    vector<STUDENT> vc = vector<STUDENT>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i].name >> vc[i].korean >> vc[i].english >> vc[i].math;
    }

    sort(vc.begin(), vc.end(), comp);

    for (int i = 0; i < N; i++) {
        cout << vc[i].name << "\n";
    }

    return 0;
}