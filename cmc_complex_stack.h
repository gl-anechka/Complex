// В пространстве имен numbers реализован класс complex_stack,
// который будет реализовывать функциональность иммутабельного стека
// комплексных чисел из предыдущей задачи.
// Реализация не содержит стандартные контейнерные классы.

#pragma once

#include "cmc_complex.h"

namespace numbers
{
    class complex_stack
    {
    private:
        complex *arr_{nullptr};
        size_t count_elem_{0};
        size_t size_{0};

    public:
        // Конструктор по умолчанию.
        complex_stack(size_t elems = 0, size_t size = 10);

        // Конструкторы, деструкторы и операции, необходимые для корректного управления памятью.
        complex_stack(const complex_stack &stack, bool is_app = false);
        ~complex_stack();

        // Метод size для получения числа элементов в стеке (возвращает size_t).
        size_t size() const;

        // Доступ к произвольному элементу стека только на чтение с помощью операции [].
        complex &operator[](size_t index) const;

        // Бинарный оператор <<, у которого первый аргумент - complex_stack, а второй
        // аргумент - complex, бинарный оператор возвращает новый стек, в который
        // добавлен указанный элемент. Исходный стек не изменяется.
        complex_stack operator<<(const complex elem) const;

        // Унарный оператор +, который возвращает элемент типа complex с вершины стека.
        complex operator+() const;

        // Унарный оператор ~, который удаляет один элемент из стека и возвращает
        // модифицированный стек, исходный стек при этом не изменяется.
        complex_stack operator~() const;

        complex_stack &operator=(const complex_stack &other);
    };
};
