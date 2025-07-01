#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    int nation_num;
    int num;
    int score;
};

bool comp(Student a, Student b) {
    return a.score > b.score;
}

int main() {
    int N;
    cin >> N;

    vector<Student> students = vector<Student>(N);
    for (int i = 0; i < N; i++) {
        cin >> students[i].nation_num >> students[i].num >> students[i].score;
    }

    sort(students.begin(), students.end(), comp);

    int nation[101] = { 0, };
    int gold, silver, bronze;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (cnt == 3) {
            break;
        }

        if (nation[students[i].nation_num] >= 2) {
            continue;
        }
        else {
            if (cnt == 0) {
                gold = i;
                nation[students[i].nation_num] += 1;
                cnt += 1;
            }
            else if (cnt == 1) {
                silver = i;
                nation[students[i].nation_num] += 1;
                cnt += 1;
            }
            else if (cnt == 2) {
                bronze = i;
                nation[students[i].nation_num] += 1;
                cnt += 1;
            }
        }
    }

    cout << students[gold].nation_num << ' ' << students[gold].num << "\n";
    cout << students[silver].nation_num << ' ' << students[silver].num << "\n";
    cout << students[bronze].nation_num << ' ' << students[bronze].num << "\n";

    return 0;
}