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

        int dong = 0;
        while(lex.first != lex.last) {
            cout << "first: " << lex.first << " Last: " << lex.last << "\n";
            tok = lex.next();
            toks.push_back(tok);
            if(dong > 10) 
                break;
        }

        //do {
        //    cout << "first: " << lex.first << " Last: " << lex.last << "\n";
        //    tok = lex.next();
        //    toks.push_back(tok);
        //} while(lex.first != lex.last);
            
        tok = lex.next();
        toks.push_back(tok);


        for(int i = 0; i < toks.size(); i++) {
            cout << "<kind: " << toks[i]->kind << ", attr: " << toks[i]->attribute <<">";
            cout << "\n";
        }
    }
}
