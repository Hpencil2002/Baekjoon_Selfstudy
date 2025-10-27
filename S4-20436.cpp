#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Info {
    int r;
    int c;
    char hand;
};

Info l, r;
string top = "qwertyuiop";
string middle = "asdfghjkl";
string bottom = "zxcvbnm";

Info find_coor(char key) {
    int _r = 0, _c = 0;
    char hand;

    for (int i = 0; i < top.size(); i++) {
        if (top[i] == key) {
            _r = 0, _c = i;
            if (i <= 4) {
                hand = 'l';
            }
            else {
                hand = 'r';
            }
        }
    }

    for (int i = 0; i < middle.size(); i++) {
        if (middle[i] == key) {
            _r = 1; _c = i;
            if (i <= 4) {
                hand = 'l';
            }
            else {
                hand = 'r';
            }
        }
    }

    for (int i = 0; i < bottom.size(); i++) {
        if (bottom[i] == key) {
            _r = 2; _c = i;
            if (i <= 3) {
                hand = 'l';
            }
            else {
                hand = 'r';
            }
        }
    }

    return { _r, _c, hand };
}

int find_dist(char key) {
    Info coor = find_coor(key);
    int dist = 0;

    if (coor.hand == 'l') {
        dist = abs(l.r - coor.r) + abs(l.c - coor.c);
        l.r = coor.r;
        l.c = coor.c;
    }
    if (coor.hand == 'r') {
        dist = abs(r.r - coor.r) + abs(r.c - coor.c);
        r.r = coor.r;
        r.c = coor.c;
    }

    return dist;
}

int main() {
    char left, right;
    string str;
    cin >> left >> right >> str;

    l = find_coor(left);
    r = find_coor(right);

    int ans = 0;
    for (char key : str) {
        ans += find_dist(key);
    }

    cout << ans + str.length();

    return 0;
}