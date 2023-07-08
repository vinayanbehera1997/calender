#include <stdio.h>

// Function to determine if a given year is a leap year
int isLeapYear(int year) {
    if (year % 400 == 0) {
        return 1;
    } else if (year % 100 == 0) {
        return 0;
    } else if (year % 4 == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to get the number of days in a given month
int getNumDays(int year, int month) {
    int numDays;

    if (month == 2) {
        if (isLeapYear(year)) {
            numDays = 29;
        } else {
            numDays = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        numDays = 30;
    } else {
        numDays = 31;
    }

    return numDays;
}

// Function to display the calendar for a given year and month
void displayCalendar(int year, int month) {
    int numDays, startDay, day;
    int i, j;

    // Determine the number of days in the month
    numDays = getNumDays(year, month);

    // Determine the day of the week (0 - Sunday, 1 - Monday, ...)
    startDay = 0; // Assume the first day of the month is Sunday

    for (i = 1; i < year; i++) {
        startDay += isLeapYear(i) ? 366 : 365;
    }

    for (i = 1; i < month; i++) {
        startDay += getNumDays(year, i);
    }

    startDay %= 7;

    // Display the calendar header
    printf("   ------- %d / %02d -------\n", year, month);
    printf("   Sun Mon Tue Wed Thu Fri Sat\n");

    // Display the calendar days
    for (i = 0; i < startDay; i++) {
        printf("    ");
    }

    day = 1;

    for (j = startDay; j < 7; j++) {
        printf("  %2d ", day);
        day++;
    }

    printf("\n");

    while (day <= numDays) {
        for (i = 0; i < 7 && day <= numDays; i++) {
            printf("  %2d ", day);
            day++;
        }
        printf("\n");
    }
}

int main() {
    int year, month;

    printf("Enter the year: ");
    scanf("%d", &year);

    printf("Enter the month (1-12): ");
    scanf("%d", &month);

    displayCalendar(year, month);

    return 0;
}
