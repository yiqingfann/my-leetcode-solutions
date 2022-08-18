// https://leetcode.com/problems/number-of-days-between-two-dates/

class Solution {
  public:
    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int daysSince1971(string date) {
        const int months[] = {0,  31, 28, 31, 30, 31, 30,
                              31, 31, 30, 31, 30, 31};

        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        // add whole years
        int res = 0;
        for (int y = 1971; y < year; ++y) {
            res += isLeapYear(y) ? 366 : 365;
        }

        // add whole months
        for (int m = 1; m < month; ++m) {
            res += months[m];
        }
        if (isLeapYear(year) && month > 2) res++;

        // add all days
        res += day;

        return res;
    }

    int daysBetweenDates(string date1, string date2) {
        return abs(daysSince1971(date1) - daysSince1971(date2));
    }
};