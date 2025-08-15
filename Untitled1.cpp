#include <TXLib.h>
#include <stdio.h>
#include <math.h>

double Discriminant(double a, double b, double c) {
    return b * b - 4.0 * a * c;
}

int korni(double a, double b, double c) {
    int D = Discriminant(a, b, c);
    if (D < 0) {
        printf("Нет корней\n");
        return 0;
    }
    else if (D == 0) {
        double x = -b / (2.0 * a);
        printf("x = %0.2lf", x);
        return 0;
    }
    else {
        double x1 = (-b - sqrt(Discriminant(a, b, c))) / (2.0 * a);
        double x2 = (-b + sqrt(Discriminant(a, b, c))) / (2.0 * a);
        printf("x1 = %0.2lf\nx2 = %0.2lf", x1, x2);
        return 0;
    }
}

int main() {
    double a, b, c;
    printf("Введите a, b и c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    korni(a, b, c);
    return 0;
}

