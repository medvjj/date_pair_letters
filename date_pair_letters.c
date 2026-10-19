#include <stdio.h>

int main(void) {
    const int daysInMonth[] = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    int day, month;

    printf("Enter a date in 2026 (day and month): ");
    if (scanf("%d %d", &day, &month) != 2) {
        printf("Input error.\n");
        return 1;
    }

    if (month < 1 || month > 12 ||
        day < 1 || day > daysInMonth[month - 1]) {
        printf("Invalid date.\n");
        return 1;
    }

    char firstOnJuly1, secondOnJuly1;

    printf("Enter a pair for July 1st: the first character a–j, the second k–v: ");
    if (scanf(" %c %c", &firstOnJuly1, &secondOnJuly1) != 2) {
        printf("Pair entry error.\n");
        return 1;
    }

    if (firstOnJuly1 < 'a' || firstOnJuly1 > 'j' ||
        secondOnJuly1 < 'k' || secondOnJuly1 > 'v') {
        printf("Invalid pair. Use the first character a-j, "
               "second k-v.\n");
        return 1;
    }

    int dayOfYear = day;
    for (int i = 0; i < month - 1; i++) {
        dayOfYear += daysInMonth[i];
    }

    int offset = dayOfYear - 182; /* July 1 is the 182nd day of 2026. */
    int firstIndex = ((firstOnJuly1 - 'a' + offset) % 10 + 10) % 10;
    int secondIndex = ((secondOnJuly1 - 'k' + offset) % 12 + 12) % 12;

    printf("A couple of symbols for this date: %c %c\n",
           'a' + firstIndex, 'k' + secondIndex);

    return 0;
}
