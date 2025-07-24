#include <iostream>
#include <string>
using namespace std;

const int MAX = 3;
const int MAX_SECOND= 60;
const int MAX_MINUTE = 60;
const int MAX_HOUR = 24;

typedef struct {
    int hour, minute, second;
} Time;

void GetTimeStruct(string input, Time &startTime, Time &endTime) {
    startTime.hour = stoi(input.substr(0, 2));
    startTime.minute = stoi(input.substr(3, 2));
    startTime.second = stoi(input.substr(6, 2));

    endTime.hour = stoi(input.substr(9, 2));
    endTime.minute = stoi(input.substr(12, 2));
    endTime.second = stoi(input.substr(15, 2));
}

bool IstimeEqual(Time startTime, Time endTime) {
    return startTime.hour == endTime.hour &&
            startTime.minute == endTime.minute &&
            startTime.second == endTime.second;
}

int ConvertTimeStructToInt(Time time) {
    return time.hour * 10000 + time.minute * 100 + time.second;
}

void IncrementTime(Time &time) {
    time.second += 1;

    if (time.second == MAX_SECOND) {
        time.second = 0;
        time.minute += 1;
    }

    if (time.minute == MAX_MINUTE) {
        time.minute = 0;
        time.hour += 1;
    }

    if (time.hour == MAX_HOUR) {
        time.hour = 0;
    }
}

int main() {
    for (int i = 0; i < MAX; i++) {
        string input;
        getline(cin, input);

        Time startTime, endTime;
        GetTimeStruct(input, startTime, endTime);

        int ans = 0;
        while (true) {
            int start = ConvertTimeStructToInt(startTime);
            int end = ConvertTimeStructToInt(endTime);

            if (start % 3 == 0) {
                ans += 1;
            }

            if (IstimeEqual(startTime, endTime)) {
                break;
            }

            IncrementTime(startTime);
        }

        cout << ans << "\n";
    }

    return 0;
}