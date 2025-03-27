// Класс complex в пространстве имен numbers для комплексных чисел над типом double.

#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

constexpr char COMMA{','};
constexpr int PREC{10};

namespace numbers
{
    class complex
    {
    private:
        double re_{0.0};
        double im_{0.0};

    public:
        // Конструкторы по умолчанию, от одного и двух аргументов.
        complex(double x = 0.0, double y = 0.0);

        // Явный (explicit) конструктор из типа std::string, который преобразовывает
        // строку в значение complex. Строка имеет формат (RE,IM), то есть вещественная
        // и мнимая части (числа типа double) записываются через запятую в круглых скобках.
        // Например, строка "(1.0,-5)" определяет комплексное число (1.0,-5.0). Проверка
        // на ошибки не требуется.
        explicit complex(const std::string& st);

        // Методы re и im для получения вещественной и мнимой части числа.
        double re() const;
        double im() const;

        // Метод abs2 для получения квадрата модуля числа.
        double abs2() const;

        // Метод abs для получения модуля числа.
        double abs() const;

        // Метод to_string, который преобразовывает комплексное число в строковое
        // представление (см. выше) и возвращает объект типа std::string. Вещественные
        // числа выводятся с 10 значащими цифрами в формате %.10g.
        std::string to_string() const;

        // Операции +=, -=, *=, /=.
        complex operator+=(const complex &val);
        complex operator-=(const complex &val);
        complex operator*=(const complex &val);
        complex operator/=(const complex &val);

        // Операции сложения, вычитания, умножения и деления в обычной инфиксной
        // форме, которые должны быть определены через соответствующие операции присваивания.
        friend complex operator+(const complex &a, const complex &b);
        friend complex operator-(const complex &a, const complex &b);
        friend complex operator*(const complex &a, const complex &b);
        friend complex operator/(const complex &a, const complex &b);

        // Префиксная операция ~, которая возвращает новое число,
        // комплексно-сопряженное к аргументу.
        complex operator~() const;

        // Префиксная операция - смены знака.
        complex operator-() const;
    };
};
