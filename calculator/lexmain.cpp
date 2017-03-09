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
        Lexer lex = Lexer(input);

        do {
            //cout << "running" << "\n";
            //cout << "first" << lex.first << "last" << lex.last <<"\n";
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
