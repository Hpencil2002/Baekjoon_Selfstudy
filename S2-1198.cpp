#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double N;
vector<pair<double, double>> vc;
vector<double> answer;

double find_len(pair<double, double> a, pair<double, double> b) {
    double aX = a.first;
    double aY = a.second;
    double bX = b.first;
    double bY = b.second;

    double sum = (aY - bY) * (aY - bY) + (aX - bX) * (aX - bX);

    return sqrt(sum);
}

void solve(double left, double mid, double right) {
    double len1 = find_len(vc[left], vc[mid]);
    double len2 = find_len(vc[right], vc[mid]);
    double diag = find_len(vc[left], vc[right]);

    double s = (len1 + len2 + diag) / 2;

    double res = s * (s - len1) * (s - len2) * (s - diag);

    answer.push_back(res);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        double x, y;
        cin >> x >> y;

        vc.push_back({ x, y });
    }

    for (double i = 0; i < N - 2; i++) {
        for (double j = i + 1; j < N - 1; j++) {
            for (double k = j + 1; k < N; k++) {
                solve(i, j, k);
            }
        }
    }

    double ans = answer[0];

    for (int i = 1; i < answer.size(); i++) {
        if (ans < answer[i]) {
            ans = answer[i];
        }
    }

    cout.setf(ios::fixed);
    cout.precision(12);
    cout << sqrt(ans);

    return 0;
}