#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<int> vc;
    int arr[4][4] = {   {0, 2, 0, 1},
                        {2, 1, 3, 0},
                        {0, 3, 2, 1},
                        {1, 0, 1, 3} };

    int N;
    string str;
    cin >> N >> str;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'A') {
            vc.push_back(0);
        }
        else if (str[i] == 'G') {
            vc.push_back(1);
        }
        else if (str[i] == 'C') {
            vc.push_back(2);
        }
        else {
            vc.push_back(3);
        }
    }

    int num = vc.size() - 1;
    for (int i = num; i > 0; i--) {
        int a = vc[i];
        int b = vc[i - 1];
        int val = arr[b][a];

        vc.erase(vc.begin() + i - 1, vc.begin() + i + 1);
        vc.push_back(val);
    }

    if (vc[0] == 0) {
        cout << "A\n";
    }
    else if (vc[0] == 1) {
        cout << "G\n";
    }
    else if (vc[0] == 2) {
        cout << "C\n";
    }
    else {
        cout << "T\n";
    }

    return 0;
}