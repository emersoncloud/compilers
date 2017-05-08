// Emerson Cloud
#include <iostream>
#include <string>
#include "ast.hpp"
#include "lex.hpp"
#include <vector>
using namespace std;

int main() {
    std::vector<Token*> toks; 
    Token* tok = new Token();
    
    string input;
    while (true) {
        getline(cin, input);    
        cout << input << "\n";
        if (input == "")
            break;
        Lexer lex = Lexer(input);

        while(lex.first != lex.last) {
            tok = lex.next();
            if (tok->kind != 25) {
                toks.push_back(tok);
            }
            if(lex.done == 1) break;
        }

        if (lex.done != 1) {
            tok = lex.next();
            toks.push_back(tok);
        }
    }
    
    for(int i = 0; i < toks.size(); i++) {
        cout << "<kind: " << toks[i]->kind << ", attr: " << toks[i]->attribute <<">";
        cout << "\n";
    }
}
