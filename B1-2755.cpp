#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    int N;
    cin >> N;

    double ans = 0.0;
    int scoreSum = 0;
    for (int i = 0; i < N; i++) {
        string name, grade;
        int score;

        cin >> name >> score >> grade;
        scoreSum += score;

        if (grade == "A+") {
            ans += 4.3 * (double)score;
        }
        else if (grade == "A0") {
            ans += 4.0 * (double)score;
        }
        else if (grade == "A-") {
            ans += 3.7 * (double)score;
        }
        else if (grade == "B+") {
            ans += 3.3 * (double)score;
        }
        else if (grade == "B0") {
            ans += 3.0 * (double)score;
        }
        else if (grade == "B-") {
            ans += 2.7 * (double)score;
        }
        else if (grade == "C+") {
            ans += 2.3 * (double)score;
        }
        else if (grade == "C0") {
            ans += 2.0 * (double)score;
        }
        else if (grade == "C-") {
            ans += 1.7 * (double)score;
        }
        else if (grade == "D+") {
            ans += 1.3 * (double)score;
        }
        else if (grade == "D0") {
            ans += 1.0 * (double)score;
        }
        else if (grade == "D-") {
            ans += 0.7 * (double)score;
        }
        else if (grade == "F") {
            ans += 0.0;
        }
    }

    ans /= (double)scoreSum;
    ans += 0.000000000001;

    cout << fixed << setprecision(2) << ans;

    return 0;
}