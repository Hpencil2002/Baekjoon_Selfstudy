#include <iostream>
#include <string>
using namespace std;

int isYoon(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int currentMonth(string month) {
	if (month == "January") {
		return 1;
	}
	else if (month == "February") {
		return 2;
	}
	else if (month == "March") {
		return 3;
	}
	else if (month == "April") {
		return 4;
	}
	else if (month == "May") {
		return 5;
	}
	else if (month == "June") {
		return 6;
	}
	else if (month == "July") {
		return 7;
	}
	else if (month == "August") {
		return 8;
	}
	else if (month == "September") {
		return 9;
	}
	else if (month == "October") {
		return 10;
	}
	else if (month == "November") {
		return 11;
	}
	else {
		return 12;
	}
}

int sumDate(int year, int month, int date) {
    int sum = 0;

    for (int i = 1; i < month; i++) {
        switch (i) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                sum += 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                sum += 30;
                break;
            case 2:
                if (isYoon(year)) {
                    sum += 29;
                }
                else {
                    sum += 28;
                }
                break;
        }
    }

    sum += date - 1;

    return sum;
}

int totalNewYear(int year, string month, string date, string currentTime) {
    int time = (currentTime[0] - '0') * 10;
    time += currentTime[1] - '0';
    time *= 60;
    time += (currentTime[3] - '0') * 10;
    time += currentTime[4] - '0';

    int mon = currentMonth(month);
    int dat = (date[0] - '0') * 10 + (date[1] - '0');
    int sum = sumDate(year, mon, dat);
    time += sum * 60 * 24;

    return time;
}

int main() {
    string month, date, currentTime;
    int year;

    cin >> month >> date >> year >> currentTime;

    long double currentYear;

    if (isYoon(year)) {
        currentYear = 366 * 24 * 60L;
    }
    else{
        currentYear = 365 * 25 * 60L;
    }

    long double ans = (totalNewYear(year, month, date, currentTime) * 100L);
    ans /= currentYear;

    cout.precision(17);
    cout << ans;

    return 0;
}