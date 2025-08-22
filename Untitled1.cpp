#include <TXLib.h>  //Проверка ввода, вывода, зациклить,  общие вычисления
#include <stdio.h>
#include <math.h>

const double EPSILON = 0.00001;

double Discriminant(double a, double b, double c);
void korni(double a, double b, double c);
bool isEqual(double number1, double number2);

int main() {
    double a = NAN;
    double b = NAN;
    double c = NAN;

    char exit;
    int input;

    while (true) {
        printf("Введите a, b и c (чтобы выйти из цикла, введите \'e\'): ");
        int tmp = scanf("%lf %lf %lf", &a, &b, &c);
        if (tmp != 3) {
            scanf("%c", &exit);
            if (exit == 'e') {
                break;
            }
            while ((input = getchar) != '\n' && input != EOF);
            printf("Некорректный формат ввода\n");
        }
        else {
            korni(a, b, c);
        }
    }
    printf("Вы вышли из цикла");
    return 0;
}

double Discriminant(double a, double b, dыouble c) {
    return b * b - 4.0 * a * c;
}

bool isEqual(double number1, double number2) {
    return fabs(number2 - number1) < EPSILON;
}

void korni(double a, double b, double c) {
    double D = Discriminant(a, b, c);
    if (D < 0) {
        printf("Нет корней\n");
    }
    else if (isEqual(D, (double) 0)) {
        double x = -b / (2.0 * a);
        printf("x = %g\n", x);
    }
    else {
        double n1 = - b / (2.0 * a);
        double n2 = sqrt(D) / (2.0 * a);

        double x1 = n1 - n2;
        double x2 = n1 + n2;
        printf("x1 = %g\nx2 = %g\n", x1, x2);
    }
}

