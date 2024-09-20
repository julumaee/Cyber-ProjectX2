#include "src/calculator.h"
#include <limits>

int main() {
    // Function calls to calculate
    // Write your all possible input scenarios here
    // Notice that calculator code written here works with floats now
    
    // All valid operations with integers:
    calculator(123, '+' , 123);
    calculator(-123, '-' , 123);
    calculator(123, '*' , 123);
    calculator(-123, '/' , 123);

    // Testing overflow
    calculator(std::numeric_limits<int>::max(), '+', 1);
    calculator(std::numeric_limits<int>::max(), '*', 2);

    // Testing underflow
    calculator(std::numeric_limits<int>::min(), '-', 1);
    calculator(std::numeric_limits<int>::min(), '/', 2);

    // Division by zero:
    calculator(123, '/' , 0);
    calculator(0, '/' , 0);

    // Invalid operator:
    calculator(123, '=' , 123);
    calculator(-123, '^' , 123);
    calculator(123, '0' , 123);
    calculator(0, '0' , 0);

    return 0;
}
