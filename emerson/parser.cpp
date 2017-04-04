#include "lexer.hpp"

#include <deque>
#include <vector>


struct stmt;
struct decl;
struct type;
struct expr;

// The parser is responsible for transforming a sequence of tokens into an ast
// The grammer for the language is defined by the various parsing functions

Symbol_Table :: std::map<string, token*> st;

struct parser {

    Expr* expression();
    Expr* Term();
    Expr* Factor();

}

struct Semantics {
    Expr* an_integer(token*);
    Expr* on_Boolean(token*);
    Expr* on_Addition(Expr* e1, Expr* e2);
}

    
    parser(const keyword_table&, symbol_table&, context&, const std::string&);

    decl* program();

    std::vector<stmt*> statmente_seq();

}


int Expr() {
    int e1 = term();
    return e1 + Expr

}

int ERest() {
    if (match_if('+')) {
        int e2 = term();
        return e2 + ERest();
    }

    return 0;
}


Expr *Term() {
    Expr* e1 = Factor();

    while (true) {
        if (match_if(Mul_tok)) {
            Expr *e2 = factor()
                e1 = new Mul_expr(e1, e2)
        }

        else if (match_if(Div_tok))

        else
            break;

    }
}


