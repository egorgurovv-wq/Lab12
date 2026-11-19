#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "Course.h"

kurs input_kurs(int n){
    kurs k;
    printf("Ввод данных курса %d:\n", n);
    printf("Введите название курса: ");
    scanf(" %s", k.kurs_name);
    printf("Введите категорию курса: ");
    scanf(" %s", k.category);
    printf("Введите количество часов: ");
    scanf(" %d", &k.hours);
    printf("Введите стоимость курса: ");
    scanf(" %f", &k.cost);
    printf("Введите формат курса: ");
    scanf(" %s", k.format);
    return k;
}

double sr_prod_kurs(kurs k1, kurs k2, kurs k3){
    return (k1.hours + k2.hours + k3.hours) / 3.0;
}

void print_kurs(kurs k1, kurs k2, kurs k3){
    if (k1.hours > sr_prod_kurs(k1, k2, k3)){
        printf("%s курс имеет продолжительность больше средней\n", k1.kurs_name);
    } else if (k2.hours > sr_prod_kurs(k1, k2, k3)){
        printf("%s курс имеет продолжительность больше средней\n", k2.kurs_name);
    } else {
        printf("%s курс имеет продолжительность больше средней\n", k3.kurs_name);
    }
}

int writefile(char *fname, kurs k1, kurs k2, kurs k3){
    FILE *out;
    if ((out = fopen(fname, "wt")) == NULL){
        printf("Ошибка открытия файла для записи\n");
        return 0;
    }
    fprintf(out, "%s %s %d %.2f %s\n", k1.kurs_name, k1.category, k1.hours, k1.cost, k1.format);
    fprintf(out, "%s %s %d %.2f %s\n", k2.kurs_name, k2.category, k2.hours, k2.cost, k2.format);
    fprintf(out, "%s %s %d %.2f %s\n", k3.kurs_name, k3.category, k3.hours, k3.cost, k3.format);
    fclose(out);
    printf("Данные успешно записаны в файл %s\n", fname);
    return 1;
}
