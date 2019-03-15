#include <iostream>
#include <cstring>

// '0'..'9' -> 0..9
// otherwise -> -1
int toInt(char c) {
    if ('0' <= c && c <= '9') {
        return c - '0';
    }

    return -1;
}

static const unsigned int MAX_DIGITS = 9;

struct Number {
    private:
        bool overflow;
        char digits[MAX_DIGITS];

    public:
        Number() : overflow(false) {
            memset(digits, 0, sizeof(char) * MAX_DIGITS);
        }

        Number (unsigned int number) : overflow(false) {
            for (int i = MAX_DIGITS - 1; i >= 0; i--) {
                digits[i] = number % 10;
                number /= 10;
            }
        }

        Number (const std::string& number) : overflow(false) {
            if (number.size() > MAX_DIGITS) {
                std::cout << "Invalid number size" << std::endl;
                exit(-1);
            }
            for (int i = MAX_DIGITS - 1; i >= 0; i--) {
                digits[i] = toInt(number.at(i));
            }
            // TODO: init from "number"
            // Note: exit(-1) with a message if number.size() > MAX_DIGITS;
        }

        void setOverflow (bool value) {
            overflow = value;
        }

        bool isOverflow() const {
            return overflow;
        }

        // TODO: learn about operator overloading in C++.
        // Note: the following two almost always come in pairs.
        char& operator[](unsigned int index) {
            return digits[index];
        }

        const char& operator[](unsigned int index) const {
            return digits[index];
        }

        friend std::ostream& operator<<(std::ostream& stream, const Number& number);
        friend Number operator+(const Number& number1, const Number& number2);
};


std::ostream& operator<<(std::ostream& stream, const Number& number) {
    unsigned int index = 0;
    while ((number[index] == 0) && (index <  MAX_DIGITS - 1)) {
        index++;
    }
    for (unsigned int i = index; i < MAX_DIGITS; i++) {
        stream << static_cast<unsigned int> (number[i]);
    }

    return stream;
}


// Don't forget about the overflow flag
Number operator+(const Number& number1, const Number& number2) {
    Number result();
    unsigned int carryOver = 0;
    for (unsigned int i = 0; i < MAX_DIGITS; i++) {
        const unsigned int sum = number1[i] + number2[i] + carryOver;
        result[i] = sum % 10;
        carryOver = ((sum / 10) > 0) ?  1 : 0;
    }
    if (carryOver) {
        result.setOverflow(true);
    }

    return result;
}



int main() {

    /* Number number1( 0 ); */
    /* std::cout << number1 << std::endl; */
    Number number2("9999999999");
    std::cout << number2 << std::endl;
    /* std::cout << number1 << " + " << number2 << " = " << (number1 + number2) << std::endl; */

    return 0;
} 
