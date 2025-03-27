#include "cmc_complex.h"

namespace numbers
{
    complex::complex(double x, double y) : re_(x), im_(y) {}

    complex::complex(const std::string& st)
    {
        std::string temp = st;
        temp.erase(temp.begin());
        temp.erase(temp.end() - 1);

        std::string real = temp.substr(0, temp.find(COMMA));
        std::string image = temp.substr(temp.find(COMMA) + 1);

        re_ = stod(real);
        im_ = stod(image);
    }

    double complex::re() const { return re_; }
    double complex::im() const { return im_; }

    double complex::abs2() const { return re_ * re_ + im_ * im_; }
    double complex::abs() const { return std::sqrt(this->abs2()); }

    std::string complex::to_string() const
    {
        std::stringstream st;
        st << std::setprecision(PREC) << '(' << re_ << ',' << im_ << ')';
        return st.str();
    }

    complex complex::operator+=(const complex &val)
    {
        re_ += val.re_;
        im_ += val.im_;
        return *this;
    }

    complex complex::operator-=(const complex &val)
    {
        re_ -= val.re_;
        im_ -= val.im_;
        return *this;
    }

    complex complex::operator*=(const complex &val)
    {
        double temp_im = re_ * val.im_ + im_ * val.re_;
        double temp_re = re_ * val.re_ - im_ * val.im_;

        re_ = temp_re;
        im_ = temp_im;
        return *this;
    }

    complex complex::operator/=(const complex &val)
    {
        double temp_re = re_ * val.re_ + im_ * val.im_;
        double temp_im = im_ * val.re_ - re_ * val.im_;

        re_ = temp_re / val.abs2();
        im_ = temp_im / val.abs2();
        return *this;
    }

    complex operator+(const complex &a, const complex &b)
    {
        complex res = a;
        res += b;
        return res;
    }

    complex operator-(const complex &a, const complex &b)
    {
        complex res = a;
        res -= b;
        return res;
    }

    complex operator*(const complex &a, const complex &b)
    {
        complex res = a;
        res *= b;
        return res;
    }

    complex operator/(const complex &a, const complex &b)
    {
        complex res = a;
        res /= b;
        return res;
    }

    complex complex::operator~() const { return complex(re_, -im_); }
    complex complex::operator-() const { return complex(-re_, -im_); }
}
