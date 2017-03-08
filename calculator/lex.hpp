// Emerson Cloud
// Compilers 

#ifndef LEX_HPP
#define LEX_HPP
#include <cassert>
#include "ast.hpp"

// Lexer for calculator
// Reads each line one by one with a new expression on each line
// Then creates toxens for each of the lexems read
// Throws an error if there is an invalid expression

#include <iostream>
using namespace std;

// Each expression simplifies into either an integer-literal or a boolean-literal
//

struct Token {
    string name;
    int attribute;
    union attribute {
        int n;
        bool b;
        char c;
    }
};
