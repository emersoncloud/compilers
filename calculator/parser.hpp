#include "lexer.hpp"

#include <deque>
#include <vector>

struct stmt;
struct decl;
struct type;
struct expr;

struct Parser {

    std::deque<Token*> tokens;

    Parser(vector<Token*> toks) {
        for (int i = 0; i < toks.size(); i++) {
            tokens.push_back(toks[i]);
        }
    }

    bool eof() {
        return toks.empty();
    }

    Token* peek() {
        if(!toks.empty())
            return toks.front();
        else
            return nullptr;
    }

    Token_kind lookahead() {
        if (Token* tok = peek())
            return tok->kind;
        else
            return eof_tok;
    }

    Token* consume() {
        assert(!eof());

        Token* tok = toks.front();
        toks.pop_front();

        return tok;
    }

    Token* match(token_kind k) {
        if (lookahead() == k) 
            return consume();
        else {
            throw std::runtime_error("Invalid math statement");
        }
    }

    Token* match_if(token_kind k) {
        if (lookahead() == k) {
            return consume();
        }
        else {
            return nullptr;
        }
    }

    void parse() {
        // parse the dang thing!
        // Create a vector to hold all fo the finalized expressions

        std::vector<Expr*> es = expression_seq();

        return sema.on_parse(es);


    }
    
    std::vector<Expr*> expression_seq() {
        std::vector<Expr*> es;
        while(!eof()) {
            Expr* e = get_expression();
            es.push_back(e);
        }
        return es;
    }

    Expr* get_expression() {
        //only define expression statements for now
        return expression_statement();
        //switch (lookahead()) {
    }

    Expr* expression_statement() {
        Expr* e = expression();
        match(semicolon_tok);
        return sema.on_expression_statement(e);
    }

    Expr* expression() {
        return additive_expression();
    }

    // Here we have to do the right recursion to parse the tokens to form
    // a single expression out of them (a statement)
    Expr* additive_expression() {
        Expr* e1 = mutliplicative_exprssion();

    }

    Expr* multiplicative_expression() {
        while (true) {
            if (match_if(Mul_tok)) {
                Expr* e2 = unary_expression();
                e1 = sema.on_mul(e1, e2);
            }
            else if (match_if(Div_tok)) {
                Expr* e2 = unary_exprssion();
                e1 = sema.on_mul(e1, e2);
            }
            else if (match_if(Rem_tok)) {
                Expr* e2 = unary_exprssion();
                e1 = sema.on_remainder(e1, e2);
            }
            else
                break;
        }
        return e1;
    }

    // Single character expressions, the root of expression statements
    Expr* unary_expression() {

        // If a minus is matched, then call unary expression again without 
        // the minus sign, but create a negative expression instead
        if (match_if(minus_tok)) {
            expr* e = unary_expression();
            return sema.on_neg(e);
        }
        else {
            return primary_expression();
        }
    }

    Expr* primary_expression() {
        switch (lookahead()) {
            case true_kw:
                return sema.on_true(consume());
            case false_kw:
                return sema.on_false(consume());
            case int_tok:
                return sema.on_int(consume());
            case id_tok:
                return id_expression();
            case lparen_tok: {
                consume();
                Expr* e = expression();
                match(rparen_tok);
                return e;
            }

            default:
                break;
        }
        std::cout << peek() << "\n";
        throw std::runtime_error("expected primary-exrpession");
    }

    Expr* id_expression() {
        //symbol* id
        return nullptr;
    }


}

//struct Semantics {
//    Expr* an_integer(token*);
//    Expr* on_Boolean(token*);
//    Expr* on_Addition(Expr* e1, Expr* e2);
//}
//
//    
//    parser(const keyword_table&, symbol_table&, context&, const std::string&);
//
//    decl* program();
//
//    std::vector<stmt*> statmente_seq();
//
//}
//
//
//int Expr() {
//    int e1 = term();
//    return e1 + Expr
//
//}
//
//int ERest() {
//    if (match_if('+')) {
//        int e2 = term();
//        return e2 + ERest();
//    }
//
//    return 0;
//}
//
//
//Expr *Term() {
//    Expr* e1 = Factor();
//
//    while (true) {
//        if (match_if(Mul_tok)) {
//            Expr *e2 = factor()
//                e1 = new Mul_expr(e1, e2)
//        }
//
//        else if (match_if(Div_tok))
//
//        else
//            break;
//
//    }
//}


