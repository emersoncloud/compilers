#ifndef LEX_HPP
#define LEX_HPP
#include "ast.hpp"

// Lexer for calculator
// Reads each line one by one with a new expression on each line
// Then creates toxens for each of the lexems read
// Throws an error if there is an invalid expression
// Each expression simplifies into either an integer-literal or a boolean-literal

struct Token {
    int kind;
    //attribute
    virtual ~Token();
};

struct Int_token : Token {
    int value;
}
struct Bool_token : Token {
    bool value;
}

enum Token_kind {
    EOF_tok = 0;
    Plus_tok = 1;
    Minus_tok = 2;
    Mult_tok = 3;
    Div_tok = 4;
    Mod_tok = 5;
    Ampersand_tok = 6;
    Or_tok = 7;
    Not_tok = 8;
    Eq_tok = 9;
    Neq_tok = 10;
    Lt_tok = 11;
    Gt_tok = 12;
    LtEq_tok = 13;
    GtEq_tok = 14;
    Qu_tok = 15;
    Colon_tok = 16;
    LeftParen_tok = 17;
    RightParen_tok = 18;
}

struct Lexer {
    const char* first;
    const char* last;
    
    something() {
        return EOF() ? 
    }

    Bool EOF() const {
        return first == last;
    }

    // depending on what lookahead i shwe can go into different switch statements
    char LookAhead() const {
        if (EOF()) {
            return 0;
        } else {
            return *first;
        }
    }
    //The last funciton we really need
    void consume() {
        if(eof()) {
            return 0;
        }
        buf += *first++;
        return buf.back();
    }
};


Token *Lexer::next() {
    ignore-space();

    switch (lookahead()) {
        case '0'..'9': consume();
                       while(!EOF() && std::isdigit(lookahead())) {
                           consume();
                       }
                       int n = std::sto(buf);
        case '<': consume();
                  if (lookahead() == '=') {
                      consume();
                      return new Token(LtEq_tok);
                  }
                  return Token(Lt_tok);

        case '>': consume();
                  if (lookahead() == '='){
                      consume();
                      return new Token(GtEq_tok);
                  }
                  return Token(Gt_tok);
        case '+': consume();
                  return Token(Plus_tok);
        case '-':
        case '*':
        case '/':
        case '%':
        case "&&":
        case "||":
        case "!":
        case "==":
        case "!=":
        case ')':
        case '0':
        case '1':
        case '9':
    }
};
