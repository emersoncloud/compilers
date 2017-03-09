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
    
    while (true) {
        string input;
        getline(cin, input);    
        if (input == "")
            break;
        Lexer lex = Lexer(input);

        do {
            tok = lex.next();
            toks.push_back(tok);
        } while(lex.first != lex.last);
            
        tok = lex.next();
        toks.push_back(tok);


        for(int i = 0; i < toks.size(); i++) {
            cout << "<kind: " << toks[i]->kind << ", attr: " << toks[i]->attribute <<">";
            cout << "\n";
        }
    }
}
