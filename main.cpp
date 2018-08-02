#include <iostream>


// '0'..'9' -> 0..9
// otherwise -> -1
int toInt(char c) {
    const unsigned int ASCII_CODE_DIFFERENCE = 48;
    if (!('0' <= c <= '9')) {
        return -1;
    }

    return c - ASCII_CODE_DIFFERENCE;
}
/*  */
/*  */
/* static const unsigned int MAX_DIGITS = 9; */
/*  */
/* struct Number { */
/*     public: */
/*         bool overflow; */
/*         unsigned int digits[MAX_DIGITS]; */
/*  */
/*         Number() : overflow(false) { */
/*             // TODO: init with 0s */
/*         } */
/*  */
/*         Number (unsigned int number) : overflow(false) { */
/*             // TODO: init from "number" */
/*         } */
/*  */
/*         Number (const std::string& number) : overflow(false) { */
/*             // TODO: init from "number" */
/*             // Note: exit(-1) with a message if number.size() > MAX_DIGITS; */
/*         } */
/*  */
/*         bool isOverflow() const { */
/*             return overflow; */
/*         } */
/*  */
/*         // TODO: learn about operator overloading in C++. */
/*         // Note: the following two almost always come in pairs. */
/*         unsigned int& operator[](unsigned int index) { */
/*             return digits[index]; */
/*         } */
/*  */
/*         const unsigned int& operator[](unsigned int index) const { */
/*             return digits[index]; */
/*         } */
/* }; */
/*  */
/*  */
/* std::ostream& operator<<(std::ostream& stream, const Number& number) { */
/*     // TODO */
/*     // z.B.: */
/*     // stream << number[i]; */
/*  */
/*     return stream; */
/* } */
/*  */
/*  */
/* // Don't forget about the overflow flag */
/* Number operator+(const Number& number1, const Number& number2) { */
/*     // TODO */
/* } */
/*  */
/*  */
/*  */
int main() {
    std::cout << toInt('0') << std::endl;

/*     Number number1( 111111111 ); */
/*     Number number2("999999999"); */
/*     std::cout << number1 << " + " << number2 << " = " << (number1 + number2) << std::endl; */
/*  */
    return 0;
} 
