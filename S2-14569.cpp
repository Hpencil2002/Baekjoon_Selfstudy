#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<unsigned long long> lectures;

unsigned long long Convert(const vector<int>& times) {
    unsigned long long binary = 0;

    for (int i = 0; i < times.size(); i++) {
        binary |= (1ULL << times[i]);
    }

    return binary;
}

int main() {
    cin >> N;

    lectures.resize(N);
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;

        vector<int> times = vector<int>(k);
        for (int j = 0; j < k; j++) {
            cin >> times[j];
        }

        lectures[i] = Convert(times);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int p;
        cin >> p;

        vector<int> students = vector<int>(p);
        for (int j = 0; j < p; j++) {
            cin >> students[j];
        }

        unsigned long long studentBit = Convert(students);

        int ans = 0;
        for (int j = 0; j < lectures.size(); j++) {
            if ((studentBit & lectures[j]) == lectures[j]) {
                ans += 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}