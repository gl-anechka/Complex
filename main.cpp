//  Программе в аргументах командной строки передаются:
//  -- Комплексное число C.
//  -- Вещественное число R.
//  -- Целое число N.
//  -- Остальные аргументы - запись функции одного комплексного аргумента в польской записи.

// На стандартный поток вывода напечатайте комплексное число I - результат вычисления
// криволинейного интеграла по замкнутому контуру - окружности с центром в точке C и радиусом R.
// Для вычисления используйте метод прямоугольников. Для этого окружность делится на N частей.

#include <iostream>
#include <cmath>

#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"

int main(int argc, char *argv[])
{
    numbers::complex C(argv[1]);
    double R = std::stod(argv[2]);
    int N = std::stoi(argv[3]);
    std::vector<std::string> expr;

    for (int i = 4; i < argc; ++i) {
        expr.push_back(argv[i]);
    }

    numbers::complex I;
    double delta_phi = 2 * M_PI / N;

    for (int i = 0; i < N; ++i) {
        double phi = (i + 0.5) * delta_phi;

        numbers::complex z(C.re() + R * cos(phi), C.im() + R * sin(phi));
        numbers::complex dz = numbers::complex(-R * sin(phi), R * cos(phi)) * delta_phi;

        I += eval(expr, z) * dz;
    }

    std::cout << I.to_string() << std::endl;
}
