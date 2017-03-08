// Emerson Cloud
// Compilers 

// Lexer for calculator
// Reads each line one by one with a new expression on each line
// Then creates toxens for each of the lexems read
// Throws an error if there is an invalid expression

#include <iostream>
#include <string>
#include "ast.hpp"
using namespace std;

// Each expression simplifies into either an integer-literal or a boolean-literal
//

int main() {

    string response;
    getline(cin, response);

    //lex(response);

    cout << "got it: " << response;

    // cin a line and feed it to the lexer
    // perform lexical analysis on each line
    // Empty lines should be ignored
    // Print the names and attributes of each token lexed from the input
}

