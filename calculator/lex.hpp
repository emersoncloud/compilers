#ifndef LEX_HPP
#define LEX_HPP
#include "ast.hpp"
#include <string>
#include <iostream>

enum Token_kind {
    EOF_tok,
    Plus_tok,
    Minus_tok,
    Mul_tok,
    Div_tok,
    Mod_tok,
    Amp_tok,
    Or_tok,
    Not_tok,
    Eq_tok,
    Neq_tok,
    Lt_tok,
    Gt_tok,
    LtEq_tok,
    GtEq_tok,
    Qu_tok,
    Colon_tok,
    LeftParen_tok,
    RightParen_tok,
    Int_tok,
    Bool_tok,
};

struct Token {
    int kind;
    int attribute;
    Token(Token_kind k, int a)
        :kind(k), attribute(a) {}
    //attribute
    virtual ~Token();
};

struct Int_token : Token {
    int value;
};
struct Bool_token : Token {
    bool value;
};


struct Lexer {
    const char* first;
    const char* last;

    int n;

    std::string buf;

    bool eof() const {
        return first == last;
    }

    // depending on what lookahead i shwe can go into different switch statements
    char lookahead() const {
        if (eof()) {
            return 0;
        } else {
            return *first;
        }
    }

    //The last funciton we really need
    void consume() {
        if(eof()) {
            std::cout <<"oh oops we are at the end!";
        }
        buf += *first++;
        //return buf.back();
    }

    Token *next();
};


Token *Lexer::next() {
    //ignore-space();
    switch (lookahead()) {
        case '<': consume();
                  if (lookahead() == '=') {
                      consume();
                      return new Token(LtEq_tok, 0);
                  }
                  return new Token(Lt_tok, 0);

        case '>': consume();
                  if (lookahead() == '='){
                      consume();
                      return new Token(GtEq_tok, 0);
                  }
                  return new Token(Gt_tok, 0);
        case '+': consume();
                  return new Token(Plus_tok, 0);
        case '-': consume();
                  return new Token(Minus_tok, 0);
        case '*': consume();
                  return new Token(Mul_tok, 0);
        case '/': consume();
                  return new Token(Div_tok, 0);
        case '%': consume();
                  return new Token(Mod_tok, 0);
        case '&': consume();
                  if (lookahead() == '&') {
                      consume();
                      return new Token(Amp_tok, 0);
                  } else {
                      std::cout << "ERRRORORORO!";
                      //call error
                  }
        case '|': consume();
                  if(lookahead() == '|') {
                      consume();
                      return new Token(Or_tok, 0);
                  } else {
                      std::cout << "ERRRORORORO!";
                  //    throw an error;
                  }
        case '=': consume();
                  if (lookahead() == '='){
                      consume();
                      return new Token(Eq_tok, 0);
                  } else {
                      std::cout << "ERRRORORORO!";
                  //    throw an error
                  }
        case '!': consume();
                  if (lookahead() == '='){
                      consume();
                      return new Token(Neq_tok, 0);
                  } else {
                      return new Token(Not_tok, 0);
                  }
        case ')': consume();
                  return new Token(LeftParen_tok, 0);
        case '(': consume();
                  return new Token(RightParen_tok, 0);
        case '0': consume();
                       while(!eof() && std::isdigit(lookahead())) {
                           consume();
                       }
                       n = std::stoi(buf);
                       return new Token(Int_tok, n);
        case '1': consume();
                       while(!eof() && std::isdigit(lookahead())) {
                           consume();
                       }
                       n = std::stoi(buf);
                       return new Token(Int_tok, n);
        case '2': consume();
                       while(!eof() && std::isdigit(lookahead())) {
                           consume();
                       }
                       n = std::stoi(buf);
                       return new Token(Int_tok, n);
        case '3': consume();
                       while(!eof() && std::isdigit(lookahead())) {
                           consume();
                       }
                       n = std::stoi(buf);
                       return new Token(Int_tok, n);
        case '4': consume();
                       while(!eof() && std::isdigit(lookahead())) {
                           consume();
                       }
                       n = std::stoi(buf);
                       return new Token(Int_tok, n);
        case '5': consume();
                       while(!eof() && std::isdigit(lookahead())) {
                           consume();
                       }
                       n = std::stoi(buf);
                       return new Token(Int_tok, n);
        case '6': consume();
                       while(!eof() && std::isdigit(lookahead())) {
                           consume();
                       }
                       n = std::stoi(buf);
                       return new Token(Int_tok, n);
        case '7': consume();
                       while(!eof() && std::isdigit(lookahead())) {
                           consume();
                       }
                       n = std::stoi(buf);
                       return new Token(Int_tok, n);
        case '8': consume();
                       while(!eof() && std::isdigit(lookahead())) {
                           consume();
                       }
                       n = std::stoi(buf);
                       return new Token(Int_tok, n);
        case '9': consume();
                       while(!eof() && std::isdigit(lookahead())) {
                           consume();
                       }
                       n = std::stoi(buf);
                       return new Token(Int_tok, n);
        //case '0': consume();
        //case '1': consume();
        //case '9': consume();
    }
};
#endif
