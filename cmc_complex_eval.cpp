#include "cmc_complex_eval.h"

namespace numbers
{
    complex eval(const std::vector<std::string> &args, const complex &z)
    {
        complex_stack stack;

        static std::map<std::string, std::function<void()>> map
        {
            {"z", [&stack, &z]() { stack = stack << z; }},
            {"+", [&stack]()
                    {
                        complex z1 = +stack;
                        stack = ~stack;
                        complex z2 = +stack;
                        stack = ~stack;
                        stack = stack << (z1 + z2);
                    }},
            {"-", [&stack]()
                    {
                        complex z1 = +stack;
                        stack = ~stack;
                        complex z2 = +stack;
                        stack = ~stack;
                        stack = stack << (z2 - z1);
                    }},
            {"*", [&stack]()
                    {
                        complex z1 = +stack;
                        stack = ~stack;
                        complex z2 = +stack;
                        stack = ~stack;
                        stack = stack << (z2 * z1);
                    }},
            {"/", [&stack]()
                    {
                        complex z1 = +stack;
                        stack = ~stack;
                        complex z2 = +stack;
                        stack = ~stack;
                        stack = stack << (z2 / z1);
                    }},
            {"!", [&stack]() { stack = stack << +stack; }},
            {";", [&stack]() { stack = ~stack; }},
            {"~", [&stack]()
                    {
                        complex val = +stack;
                        stack = ~stack;
                        stack = stack << (~val);
                    }},
            {"#", [&stack]()
                    {
                        complex val = +stack;
                        stack = ~stack;
                        stack = stack << (-val);
                    }}
        };

        for (const auto &arg : args) {
            if (arg[0] != '(') {
                map[arg]();
            } else {
                stack = stack << complex(arg);
            }
        }

        return +stack;
    }
};
