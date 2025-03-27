#include "cmc_complex_stack.h"

namespace numbers
{

    complex_stack::complex_stack(size_t elems, size_t size) : count_elem_(elems), size_(size)
    {
        arr_ = static_cast<complex *>(::operator new(size_ * sizeof(complex)));
    }

    complex_stack::complex_stack(const complex_stack &stack, bool is_app) : count_elem_(stack.count_elem_ + is_app), \
                size_(stack.size_)
    {
        if (count_elem_ >= size_) {
            size_ *= 2;
        }
        arr_ = static_cast<complex *>(::operator new(size_ * sizeof(complex)));

        for (size_t i = 0; i < count_elem_; ++i) {
            arr_[i] = stack.arr_[i];
        }
    }

    complex_stack::~complex_stack()
    {
        for (size_t i = 0; i < count_elem_; ++i) {
            arr_[i].~complex();
        }
        ::operator delete(arr_);
    }

    size_t complex_stack::size() const { return count_elem_; }

    complex &complex_stack::operator[](size_t index) const { return arr_[index]; }

    complex_stack complex_stack::operator<<(const complex elem) const
    {
        complex_stack res(*this, true);
        res[count_elem_] = elem;
        return res;
    }

    complex complex_stack::operator+() const { return arr_[count_elem_ - 1]; }

    complex_stack complex_stack::operator~() const
    {
        complex_stack res(count_elem_ - 1, size_);
        for (size_t i = 0; i < count_elem_ - 1; ++i) {
            res[i] = arr_[i];
        }
        return res;
    }

    complex_stack &complex_stack::operator=(const complex_stack &other)
    {
        if (this != &other)
        {
            complex_stack tmp(other);
            count_elem_ = other.count_elem_;
            size_ = other.size_;
            std::swap(tmp.arr_, this->arr_);

        }
        return *this;
    }
};
