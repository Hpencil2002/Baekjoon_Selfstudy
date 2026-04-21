#include <iostream>
#include <string>
#include <map>
using namespace std;

int N;
map<string, string> mp;
string s;
int rD, rA, X, isC;
string bit3[8] = { "000", "001", "010", "011", "100", "101", "110", "111" };
string bit4[16] = { "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111" };

void solve() {
    cin >> s >> rD >> rA >> X;
    if (s.back() == 'C') {
        isC = 1;
        s.pop_back();
    }
    else {
        isC = 0;
    }

    cout << mp[s] << isC << '0' << bit3[rD] << bit3[rA];
    if (isC) {
        cout << bit4[X] << "\n";
    }
    else {
        cout << bit3[X] << '0' << "\n";
    }
}

int main() {
    mp.insert(make_pair("ADD", "0000"));
	mp.insert(make_pair("SUB", "0001"));
	mp.insert(make_pair("MOV", "0010"));
	mp.insert(make_pair("AND", "0011"));
	mp.insert(make_pair("OR", "0100"));
	mp.insert(make_pair("NOT", "0101"));
	mp.insert(make_pair("MULT", "0110"));
	mp.insert(make_pair("LSFTL", "0111"));
	mp.insert(make_pair("LSFTR", "1000"));
	mp.insert(make_pair("ASFTR", "1001"));
	mp.insert(make_pair("RL", "1010"));
	mp.insert(make_pair("RR", "1011"));

    cin >> N;
    while (N--) {
        solve();
    }

    return 0;
}