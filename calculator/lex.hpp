#ifndef LEX_HPP
#define LEX_HPP
#include "ast.hpp"
#include <cassert>
#include <string>
#include <iostream>

enum Token_kind {
    EOF_tok, Plus_tok, 
    Minus_tok, Mul_tok,
    Div_tok, Mod_tok, 
    Amp_tok, Or_tok,
    Not_tok, Eq_tok,
    Neq_tok, Lt_tok,
    Gt_tok,  LtEq_tok, 
    GtEq_tok, Qu_tok,
    Colon_tok, LeftParen_tok,
    RightParen_tok, Int_tok,
    Bool_tok,
};

struct Token {
    int kind;
    int attribute;
    Token() {}
    Token(Token_kind k, int a)
        :kind(k), attribute(a) {}
    virtual ~Token() = default;
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

    Lexer() {
        n = 0;
        buf = "";
        const char* first = nullptr;
        //const char* last = nullptr;
    }

    Lexer(std::string str) {
            first = &str[0];
            last = &str[str.length()-1];
    }

    bool eof() {
        bool teest = first == last;
        //std::cout << teest;
        //std::cout << "someone is using this!";
        return first == last;
    }

    char lookahead() const {
        //if (eof()) {
        //    assert("donezo!");
        //    return 0;
        //} 
        //else {
            return *first;
        //}
    }

    void consume() {
        //if(eof()) {
        //    std::cout <<"oh oops we are at the end!";
        //}
        buf += *first++;
        std::cout << "HEREs the buffer:" << buf << "\n";
    }

    Token *next();
};


Token *Lexer::next() {
    if (lookahead() == ' ') {
        std::cout << "we hit the if statement" << "\n";
        consume();
    }
    switch (lookahead()) {
        //case ' ': consume();
        //          buf = "";
        //          return;
        case '<': consume();
                  if (lookahead() == '=') {
                      consume();
                      buf = "";
                      return new Token(LtEq_tok, 0);
                  }
                  buf = "";
                  return new Token(Lt_tok, 0);
        case '>': consume();
                  if (lookahead() == '='){
                      consume();
                      buf = "";
                      return new Token(GtEq_tok, 0);
                  }
                  buf = "";
                  return new Token(Gt_tok, 0);
        case '+': consume();
                      buf = "";
                  return new Token(Plus_tok, 0);
        case '-': consume();
                      buf = "";
                  return new Token(Minus_tok, 0);
        case '*': consume();
                      buf = "";
                  return new Token(Mul_tok, 0);
        case '/': consume();
                      buf = "";
                  return new Token(Div_tok, 0);
        case '%': consume();
                      buf = "";
                  return new Token(Mod_tok, 0);
        case '&': consume();
                  if (lookahead() == '&') {
                      consume();
                      buf = "";
                      return new Token(Amp_tok, 0);
                  } else {
                      std::cout << "ERRRORORORO!";
                  }
        case '|': consume();
                  if(lookahead() == '|') {
                      consume();
                      buf = "";
                      return new Token(Or_tok, 0);
                  } 
                  // else {
                  //     std::cout << "ERRRORORORO!";
                  // }
        case '=': consume();
                  if (lookahead() == '='){
                      consume();
                      buf = "";
                      return new Token(Eq_tok, 0);
                  } 
                  //else {
                  //    std::cout << "ERRRORORORO!";
                  //}
        case '!': consume();
                  if (lookahead() == '='){
                      consume();
                      buf = "";
                      return new Token(Neq_tok, 0);
                  } else {
                      buf = "";
                      return new Token(Not_tok, 0);
                  }
        case ')': consume();
                  buf = "";
                  return new Token(LeftParen_tok, 0);
        case '(': consume();
                  buf = "";
                  return new Token(RightParen_tok, 0);
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9': consume();
                  while(std::isdigit(lookahead())) {
                        consume();
                  }
                  n = std::stoi(buf);
                  Token *tok = new Token(Int_tok, n);
                  buf = "";
                  return tok;
    }
};
#endif
