#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

struct Kurs{
    char kurs_name[30];
    char category[30];
    int hours;
    float cost;
    char format[30];
};

typedef struct Kurs kurs;

kurs input_kurs(int n);
double sr_prod_kurs(kurs k1, kurs k2, kurs k3);
void print_kurs(kurs k1, kurs k2, kurs k3);
int writefile(char *fname, kurs k1, kurs k2, kurs k3);

int main(){
    setlocale(LC_ALL, "RUS");
    int Choice;

    printf("Введите данные для 3 курсов:\n");
    kurs k1 = input_kurs(1);
    kurs k2 = input_kurs(2);
    kurs k3 = input_kurs(3);
    do{
        printf("==================Меню================\n");
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
