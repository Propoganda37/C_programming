// 1 Вариант. Программа упаковывает 4 байта в беззнаковое целое и распаковывает обратно
#include <stdio.h>

// Функция для вывода упакованного числа
void print_number2(unsigned int number)
{
    for (int i = 31; i > -1; i--)
    {
        printf("%d", number >> i & 0x1);
    }
}

int main(void)
{
    unsigned int byte1, byte2, byte3, byte4;
    // Ввод значений
    printf("Введите четыре байта в десятичной СС:\n");
    int rc = scanf("%u%u%u%u", &byte1, &byte2, &byte3, &byte4);
    // Проверка ввода
    if (rc == 4)
    {
        if (byte1 < 256 && byte2 < 256 && byte3 < 256 && byte4 < 256)
        {
            unsigned int number2 = byte1 << 24 | byte2 << 16 | byte3 << 8 | byte4;
            // Вывод результата
            printf("Result: ");
            print_number2(number2);
            printf(" %d %d %d %d\n", number2 >> 24 & 0xFF, number2 >> 16 & 0xFF,
            number2 >> 8 & 0xFF, number2 & 0xFF);
        }
        // Сообщение о неверно введённом числе
        else
        {
            printf("Error: одно из введённых чисел занимает в памяти больше одного байта\n");
            return 1;
        }
    }
    // Сообщение о неверном вводе
    else
    {
        printf("Error: неверный ввод\n");
        return 1;
    }
    return 0;
}

