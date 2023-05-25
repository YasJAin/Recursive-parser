#include <iostream>
#include <string>
std::string input; 
int position = 0;       
void match(char expected) {
    if (input[position] == expected) {
        position++; 
    } else {
        std::cout << "Syntax error: Expected '" << expected << "', but got '"
                  << input[position] << "'" << std::endl;
        exit(1);
    }
}
void parse_E();
void parse_F() {
    if (input[position] == '(') {
        match('(');
        parse_E();
        match(')');
    } else if (isalpha(input[position])) {
        match(input[position]);  // Assuming id is a single character
    } else {
        std::cout << "Syntax error: Expected '(' or 'id', but got '"
                  << input[position] << "'" << std::endl;
        exit(1);
    }
}
void parse_T_prime() {
    if (input[position] == '*') {
        match('*');
        parse_F();
        parse_T_prime();
    }
}
void parse_T() {
    parse_F();
    parse_T_prime();
}
void parse_E_prime() {
    if (input[position] == '+') {
        match('+');
        parse_T();
        parse_E_prime();
    }
}
void parse_E() {
    parse_T();
    parse_E_prime();
}
int main() {
    std::cout << "Enter the input string: ";
    std::cin >> input;
    parse_E();
    if (position == input.length()) 
        std::cout << "Input string is valid!" << std::endl;
    else {
        std::cout << "Syntax error: Unexpected extra characters after position "
                  << position << std::endl;
    }
    return 0;
}
