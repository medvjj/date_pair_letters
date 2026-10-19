#include <stdio.h>

int main(void) {
    const int daysInMonth[] = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    int day, month;

    printf("Введите дату в 2026 году (день и месяц): ");
    if (scanf("%d %d", &day, &month) != 2) {
        printf("Ошибка ввода.\n");
        return 1;
    }

    if (month < 1 || month > 12 ||
        day < 1 || day > daysInMonth[month - 1]) {
        printf("Некорректная дата.\n");
        return 1;
    }

    char firstOnJuly1, secondOnJuly1;

    printf("Введите пару для 1 июля: первый символ a-j, второй k-v: ");
    if (scanf(" %c %c", &firstOnJuly1, &secondOnJuly1) != 2) {
        printf("Ошибка ввода пары.\n");
        return 1;
    }

    if (firstOnJuly1 < 'a' || firstOnJuly1 > 'j' ||
        secondOnJuly1 < 'k' || secondOnJuly1 > 'v') {
        printf("Недопустимая пара. Используйте первый символ a-j, "
               "второй k-v.\n");
        return 1;
    }

    int dayOfYear = day;
    for (int i = 0; i < month - 1; i++) {
        dayOfYear += daysInMonth[i];
    }

    int offset = dayOfYear - 182; /* 1 июля — 182-й день 2026 года. */
    int firstIndex = ((firstOnJuly1 - 'a' + offset) % 10 + 10) % 10;
    int secondIndex = ((secondOnJuly1 - 'k' + offset) % 12 + 12) % 12;

    printf("Пара для этой даты: %c %c\n",
           'a' + firstIndex, 'k' + secondIndex);

    return 0;
}
