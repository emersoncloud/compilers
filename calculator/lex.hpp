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
    Bool_tok, Comm_tok,
    BitLeft_tok, BitRight_tok,
    Xor_tok, Space_tok,
};

struct Token {
    int kind;
    std::string attribute;
    Token() {}
    Token(Token_kind k, int a)
        :kind(k), attribute(std::to_string(a)) {}
    Token(Token_kind k, std::string str)
        :kind(k), attribute(str) {}
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
    bool done;
    std::string buf;

    Lexer() {
        n = 0;
        buf = "";
        const char* first = nullptr;
        const char* last = nullptr;
    }

    Lexer(std::string str) {
            first = &str[0];
            last = &str[str.length()-1];
            done = false;
    }

    bool eof() {
        return first == last;
    }

    char lookahead() const {
        return *first;
    }

    void consume() {
            done = eof();
            buf += *first++;
    }

    void comments() {
        while (first != last) {
            consume();
        }
    }

    Token *next();
};


Token *Lexer::next() {
    Token *tok;
    std::string temp;
    //std::cout << "lookahead::"<<lookahead() << "\n";
    //std::cout << "first::"<<first<< "\n";

    if (lookahead() == '#') {
        comments();
        temp = buf; 
        buf = "";
        return new Token(Comm_tok, temp);
    }
    if (eof()) {
        buf = "";
        return new Token(EOF_tok, "");
    }
    switch (lookahead()) {
        case ' ': consume();
                  buf = "";
                  return new Token(Space_tok, "");
        case '?': consume();
                  buf = "";
                  return new Token(Qu_tok, "");
        case ':': consume();
                  buf = "";
                  return new Token(Colon_tok, "");
        case '<': consume();
                  if (lookahead() == '=') {
                      consume();
                      buf = "";
                      return new Token(LtEq_tok, "");
                  }
                  if (lookahead() == '<') {
                      consume();
                      buf = "";
                      return new Token(BitLeft_tok, "");
                  }
                  buf = "";
                  return new Token(Lt_tok, "");
        case '>': consume();
                  if (lookahead() == '='){
                      consume();
                      buf = "";
                      return new Token(GtEq_tok, "");
                  }
                  if (lookahead() == '>') {
                      consume();
                      buf = "";
                      return new Token(BitRight_tok, "");
                  }
                  buf = "";
                  return new Token(Gt_tok, "");
        case '+': consume();
                      buf = "";
                  return new Token(Plus_tok, "");
        case '-': consume();
                      buf = "";
                  return new Token(Minus_tok, "");
        case '*': consume();
                      buf = "";
                  return new Token(Mul_tok, "");
        case '/': consume();
                      buf = "";
                  return new Token(Div_tok, "");
        case '%': consume();
                      buf = "";
                  return new Token(Mod_tok, "");
        case '&': consume();
                  if (lookahead() == '&') {
                      consume();
                      buf = "";
                      return new Token(Amp_tok, "");
                  }
        case '|': consume();
                  if(lookahead() == '|') {
                      consume();
                      buf = "";
                      return new Token(Or_tok, "");
                  } 
        case '=': consume();
                  if (lookahead() == '='){
                      consume();
                      buf = "";
                      return new Token(Eq_tok, "");
                  } 
        case '!': consume();
                  if (lookahead() == '='){
                      consume();
                      buf = "";
                      return new Token(Neq_tok, "");
                  } else {
                      buf = "";
                      return new Token(Not_tok, "");
                  }
        case ')': consume();
                  buf = "";
                  return new Token(LeftParen_tok, "");
        case '(': consume();
                  buf = "";
                  return new Token(RightParen_tok, "");
        case '^': consume();
                  buf = "";
                  return new Token(Xor_tok, "");
        case 't':consume();
                 if (lookahead() == 'r') {
                     consume();
                     if (lookahead() == 'u') {
                         consume();
                         if (lookahead() == 'e') {
                             consume();
                             buf = "";
                             return new Token(Bool_tok, 1);
                         }
                     }
                 }
        case 'f': consume();
                  if (lookahead() == 'a') {
                      consume();
                    if (lookahead() == 'l') {
                        consume();
                        if (lookahead() == 's') {
                            consume();
                            if (lookahead() == 'e') {
                                consume();
                                buf = "";
                                return new Token(Bool_tok, 0);
                            }
                        }
                    }
                  }
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
                  tok = new Token(Int_tok, buf);
                  buf = "";
                  return tok;
        default: return new Token(Bool_tok, "Default");
    }
};
#endif
