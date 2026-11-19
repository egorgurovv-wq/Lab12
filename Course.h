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