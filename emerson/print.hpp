#include "ast.hpp"
#include <iostream>

//Visitor function to determine if an expression needs parenthesis
//during printing
bool needs_parens(Expr* e) {
    struct V : Expr::Visitor {
        bool r;
        void visit(Bool_expr*e) { 
            r = false; 
        }
        void visit(And_expr*e) { 
            r = true; 
        }
        void visit(Or_expr*e) { 
            r = true; 
        }
        void visit(Not_expr*e) { 
            r = true; 
        }
        void visit(Xor_expr*e) { 
            r = true; 
        }
        void visit(Int_expr* e) {
            r = false;
        }
        void visit(Add_expr*e) {
            r = true;
        }   
        void visit(Sub_expr*e) {
            r = true;
        }
        void visit(Mul_expr*e) {
            r = true;
        }
        void visit(Div_expr*e) {
            r = true;
        }
        void visit(Mod_expr*e) {
            r = true;
        }
        void visit(Neg_expr*e) {
            r = true;
        }
        void visit(Les_expr*e) {
            r = true;
        }
        void visit(Gre_expr*e) {
            r = true;
        }
        void visit(LOE_expr*e) {
            r = true;
        }
        void visit(GOE_expr*e) {
            r = true;
        }
        void visit(Eq_expr*e) {
            r = true;
        }
        void visit(Neq_expr*e) {
            r = true;
        }
        void visit(Cond_expr*e) {
            r = true;
        }
    };

    V vis;
    e->accept(vis);
    return vis.r;
}

//Print function that prints the expression
void print(Expr* e) {
    struct V: Expr::Visitor {
        void print_enclosed(Expr* e) {
            if(needs_parens(e)) {
                std::cout << '(';
                print(e);
                std::cout << ')';
            }
            else {
                print(e);
            }
        }
    
        void visit(Bool_expr* e) {
            if(e->val)
                std::cout << "true";
            else
                std::cout << "false";
        }

        void visit(Int_expr* e) {
            std::cout << e->val;
        }

        void visit(And_expr* e) {
            print_enclosed(e->e1);
            std::cout << " & ";
            print_enclosed(e->e2);
        }
        void visit(Or_expr* e) {
            print_enclosed(e->e1);
            std::cout << " | ";
            print_enclosed(e->e2);
        }
        void visit(Not_expr* e) {
            std::cout << '!';
            print_enclosed(e->e1);
        }
        void visit(Xor_expr* e) {
            print_enclosed(e->e1);
            std::cout << '^';
            print_enclosed(e->e2);
        }
        void visit(Add_expr* e) {
            print_enclosed(e->e1);
            std::cout << '+';
            print_enclosed(e->e2);
        }
        void visit(Sub_expr* e) {
            print_enclosed(e->e1);
            std::cout << '-';
            print_enclosed(e->e2);
        }
        void visit(Mul_expr* e) {
            print_enclosed(e->e1);
            std::cout << '*';
            print_enclosed(e->e2);
        }
        void visit(Div_expr* e) {
            print_enclosed(e->e1);
            std::cout << '/';
            print_enclosed(e->e2);
        }
        void visit(Mod_expr* e) {
            print_enclosed(e->e1);
            std::cout << '%';
            print_enclosed(e->e2);
        }
        void visit(Neg_expr*e ) {
            std::cout << '-';
            print_enclosed(e->e1);
        }
        void visit(Les_expr* e) {
            print_enclosed(e->e1);
            std::cout << '<';
            print_enclosed(e->e2);
        }
        void visit(Gre_expr* e) {
            print_enclosed(e->e1);
            std::cout << '>';
            print_enclosed(e->e2);
        }
        void visit(LOE_expr* e) {
            print_enclosed(e->e1);
            std::cout << "<=";
            print_enclosed(e->e2);
        }
        void visit(GOE_expr* e) {
            print_enclosed(e->e1);
            std::cout << ">=";
            print_enclosed(e->e2);
        }
        void visit(Eq_expr* e) {
            print_enclosed(e->e1);
            std::cout << "==";
            print_enclosed(e->e2);
        }
        void visit(Neq_expr* e) {
            print_enclosed(e->e1);
            std::cout << "!=";
            print_enclosed(e->e2);
        }
        void visit(Cond_expr* e) {
            std::cout << "if: (";
            print_enclosed(e->e1);
            std::cout << ") then: (";
            print_enclosed(e->e2);
            std::cout << ") else: (";
            print_enclosed(e->e3);
            std::cout << ")";
        }
    };
    V vis;
    e->accept(vis); 
}
