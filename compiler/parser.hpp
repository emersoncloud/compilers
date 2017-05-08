#include "lex.hpp"

#include <deque>
#include <vector>

struct Parser {

    std::deque<Token*> tokens;

    // Constructor that takes a vector of tokens
    Parser(std::vector<Token*> toks) {
        for (int i = 0; i < toks.size(); i++) {
            tokens.push_back(toks[i]);
        }
    }

    // Helper Functions that are used within the class
    bool eof() {
        return tokens.empty();
    }

    Token* peek() {
        if(!tokens.empty())
            return tokens.front();
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

        Token* tok = tokens.front();
        tokens.pop_front();

        return tok;
    }

    Token* match(token_kind k) {
        if (lookahead() == k) 
            return consume();
        else {
            throw std::runtime_error("Invalid match statement");
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

    // END helper functions

    void parse() {
        // parse the dang thing!
        // Create a vector to hold all fo the finalized expressions

        std::vector<Expr*> es = expression_seq();
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

        // With switch on lookahead we can determine if the next token is a
        // declaration token. And then create a new variable based on that
        // information
        // switch (lookahead()) { ... }
    }

    Expr* expression_statement() {

        // Pull out an expression
        Expr* e = expression();

        // Then match a semicolon to know the expression is finished
        match(semicolon_tok);
        return e;
    }

    Expr* expression() {
        return additive_expression();
    }

    // Here we have to do the right recursion to parse the tokens to form
    // a single expression out of them (a statement)
    Expr* additive_expression() {
        Expr* e1 = mutliplicative_exprssion();
        while (true) {
            if (match_if(Plus_tok)) {
                Expr* e2 = unary_expression();
                e1 = new Add_expr(e1, e2);
            }
            else if (match_if(Minus_tok)) {
                Expr* e2 = unary_exprssion();
                e1 = new Sub_expr(e1, e2);
            }
            else
                break;
        }
        return e1;

    }

    Expr* multiplicative_expression() {
        while (true) {
            if (match_if(Mul_tok)) {
                Expr* e2 = unary_expression();
                e1 = new Mul_expr(e1, e2);
            }
            else if (match_if(Div_tok)) {
                Expr* e2 = unary_exprssion();
                e1 = new Div_expr(e1, e2);
            }
            else if (match_if(Rem_tok)) {
                Expr* e2 = unary_exprssion();
                e1 = new Mod_expr(e1, e2);
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
            return new Not_expr(e);
        }
        else {
            return primary_expression();
        }
    }

    Expr* primary_expression() {
        switch (lookahead()) {
            case true_kw:
                consume();
                return new Bool_expr(true);
            case false_kw:
                consume();
                return new Bool_expr(false);
            case int_tok:
                Int_token* tok = consume();
                return new Int_expr(tok->value);
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


};

