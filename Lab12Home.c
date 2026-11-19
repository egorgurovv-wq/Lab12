#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "Course.h"

int main(){
    setlocale(LC_ALL, "RUS");
    int Choice;

    printf("Введите данные для 3 курсов:\n");
    kurs k1 = input_kurs(1);
    kurs k2 = input_kurs(2);
    kurs k3 = input_kurs(3);
    do{
        printf("\n==================Меню================\n");
        printf("1. Вывод данных курсов, продолжительность которых больше средней\n");
        printf("2. Вычисление средней продолжительности курсов\n");
        printf("3. Запись данных курсов в файл\n");
        printf("0. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &Choice);

        switch (Choice){
            case 1:
                print_kurs(k1, k2, k3);
                break;
            case 2: {
                double avg_hours = sr_prod_kurs(k1, k2, k3);
                printf("Средняя продолжительность курса: %.2f часов\n", avg_hours);
                break;
            }
            case 3:
                writefile("courses.txt", k1, k2, k3);
                break;
            case 0:
                printf("Выход из программы\n");
                break;
            default:
                printf("Неверный пункт меню\n");
                break;
        }

    }while (Choice != 0);

    return 0;
}

