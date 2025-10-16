#include "math_lib.h"
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <vector>

namespace MathLib
{
    bool isEqual(double a, double b, double tolerance)
    {
        return std::abs(a - b) <= tolerance;
    }

    bool isPrime(int n)
    {
        if (n <= 1)
            return false;

        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    int leastCommonMultiple(int a, int b)
    {
        int lcm = 1;
        int maxNum = std::max(a, b);
        for (int i = maxNum; i <= a * b; i += maxNum)
        {
            if (i % a == 0 && i % b == 0)
            {
                lcm = i;
                break;
            }
        }
        return lcm;
    }

    int GCD(int a, int b)
    {
        if (b == 0) return a;
        return GCD(b, a % b);
    }

    
    std::vector<double> solveQuadraticEquation(double a, double b, double c)
    {
        if (a == 0)
        {
            throw std::invalid_argument("a cannot be 0 in a quadratic equation");
        }

        double D = b * b - 4 * a * c;
        std::vector<double> roots;

        if (D > 0)
        {
            double x1 = (-b + std::sqrt(D)) / (2 * a);
            double x2 = (-b - std::sqrt(D)) / (2 * a);
            roots.push_back(x1);
            roots.push_back(x2);
        }
        else if (D == 0)
        {
            double x = -b / (2 * a);
            roots.push_back(x);
        }
       
        return roots;
    }
}


