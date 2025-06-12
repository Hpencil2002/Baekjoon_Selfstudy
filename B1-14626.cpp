#include <iostream>
#include <string>
using namespace std;

int main() {
    string ISBN;
    int sum = 0;

    cin >> ISBN;
    
    int loc = ISBN.find('*');
    for (int i = 0; i < 10; i++) {
        sum = 0;
        ISBN[loc] = i + '0';

        for (int j = 0; j < 13; j++) {
            if (j % 2 == 1) {
                sum += (ISBN[j] - '0') * 3;
                continue;
            }
            sum += (ISBN[j] - '0');
        }

        if (sum % 10 == 0) {
            cout << ISBN[loc];
            return 0;
        }
    }
}