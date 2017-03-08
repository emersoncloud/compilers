// Emerson Cloud
// Compilers 

// Lexer for calculator
// Reads each line one by one with a new expression on each line
// Then creates toxens for each of the lexems read
// Throws an error if there is an invalid expression

#include <iostream>
#include <string>
#include "ast.hpp"
#include "lex.hpp"
using namespace std;

// Each expression simplifies into either an integer-literal or a boolean-literal
//

int main() {
    string response;
    getline(cin, response);

    cout << "got it: " << response << "\n";

    Token *tok =  new Token(Int_tok, 0);

    //cout << "hows this work?: " << tok.kind << " : " << tok.attribute << "\n";

    Lexer lex = Lexer();
    char c = ' ';

    lex.first = &response[0];

    cout << "Lex.first: " << lex.first << "\n";
    cout << "Buffer: " << lex.buf << "\n";
    cout << "Char c: " << c << "\n";

    //lex.consume();

    cout << "Buffer: " << lex.buf << "\n";

    c = lex.lookahead();
    cout << "Lex.first: " << lex.first << "\n";
    cout << "Buffer: " << lex.buf << "\n";
    cout << "Char c: " << c << "\n";


    cout << "\n\n";
    tok = lex.next();
    cout << "Lex.first: " << lex.first << "\n";
    cout << "Buffer: " << lex.buf << "\n";
    cout << "Token kind: " << tok->kind << "attribute: " << tok->attribute << "\n";

    cout << "\n\n";
    tok = lex.next();
    cout << "Lex.first: " << lex.first << "\n";
    cout << "Buffer: " << lex.buf << "\n";
    cout << "Token kind: " << tok->kind << "attribute: " << tok->attribute << "\n";
    // cin a line and feed it to the lexer
    // perform lexical analysis on each line
    // Empty lines should be ignored
    // Print the names and attributes of each token lexed from the input
}

