#include <TXLib.h>
#include <stdio.h>
#include <math.h>

const double EPSILON = 0.00001;
const int LENGTH_ARRAY = 5, WEIGHT_ARRAY = 6;

double numberForTest[LENGTH_ARRAY][WEIGHT_ARRAY] = {
        {1, -5, 6, 2, 2, 3},
        {1,  1, 1, 0, NAN, NAN},
        {1, -4, 4, 1, 2, 2},
        {0, 0, 0, 0, NAN, NAN},
        {1, -5, 6, 2, 3, 2}
    };

double Discriminant(double a, double b, double c);
int SolveSquare(double a, double b, double c, double* x1, double* x2);
bool IsEqual(double number1, double number2);
void SolveTest(double* x1, double* x2);

int main() {
    double x1 = NAN, x2 = NAN;
    SolveTest(&x1, &x2);
    return 0;
}

double Discriminant(double a, double b, double c) {
    return b * b - 4.0 * a * c;
}

bool IsEqual(double number1, double number2) {
    return fabs(number2 - number1) < EPSILON;
}

int SolveSquare(double a, double b, double c, double* x1, double* x2) {
    if (IsEqual(a, 0) && IsEqual(b, 0)) {
        *x1 = NAN;
        *x2 = NAN;
        return 0;
    }
    else if (IsEqual(a, 0)) {
        *x1 = -c / b;
        *x2 = *x1;
        return 1;
    }
    else if (IsEqual(b, 0)) {
        double t = -c / a;
        if (t < 0) {
            *x1 = NAN;
            *x2 = NAN;
            return 0;
        }
        else {
            *x1 = -sqrt(t);
            *x2 = sqrt(t);
            if (IsEqual(*x1, *x2)) {
                return 1;
            }
            else {
                return 2;
            }
        }
    }

    double D = Discriminant(a, b, c);
    if (D < 0) {
        *x1 = NAN;
        *x2 = NAN;
        return 0;
    }
    else if (IsEqual(D, 0.0)) {
        *x1 = -b / (2.0 * a);
        *x2 = *x1;
        return 1;
    }
    else {
        double n1 = - b / (2.0 * a);
        double n2 = sqrt(D) / (2.0 * a);

        *x1 = n1 - n2;
        *x2 = n1 + n2;
        return 2;
    }
}

void SolveTest(double* x1, double* x2) {
    extern double numberForTest[LENGTH_ARRAY][WEIGHT_ARRAY];
    for (int i = 0; i < LENGTH_ARRAY; i++) {
        int solution = SolveSquare(numberForTest[i][0], numberForTest[i][1], numberForTest[i][2], x1, x2);

        bool isCorrect = false;

        if (solution != (int)numberForTest[i][3]) {
            isCorrect = false;
        }
        else if (solution == 0) {
            isCorrect = isnan(*x1) && isnan(*x2);
        }
        else {
            isCorrect = (IsEqual(*x1, numberForTest[i][4]) && IsEqual(*x2, numberForTest[i][5])) || (IsEqual(*x1, numberForTest[i][5]) && IsEqual(*x2, numberForTest[i][4]));
        }

        if (!isCorrect) {
            printf("Error: SolveSquare(%g, %g, %g) -> %d, x1 = %g, x2 = %g "
                   "(should be %g, x1 = %g, x2 = %g)\n",
                   numberForTest[i][0], numberForTest[i][1], numberForTest[i][2],
                   solution, *x1, *x2,
                   numberForTest[i][3], numberForTest[i][4], numberForTest[i][5]);
        }
        else {
            printf("Correct: SolveSquare(%g, %g, %g) -> %d, x1 = %g, x2 = %g\n",
                   numberForTest[i][0], numberForTest[i][1], numberForTest[i][2],
                   solution, *x1, *x2);
        }
    }
}
