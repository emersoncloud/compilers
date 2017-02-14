#include <iostream>
#include "ast.hpp"
#include "value.hpp"

//Function to check if an expression is valid
Type* check(Context& cxt, Expr* e) {
    struct V : Expr::Visitor {
        Context& cxt;
        Type* r;

        V(Context& c) : cxt(c) { }

        void visit(Bool_expr* e) {
            r = &cxt.bool_type;
        }
        void visit(Int_expr* e) {
            r = &cxt.int_type;
        }
        void visit(And_expr* e) {
            assert(check(cxt, e->e1) == &cxt.bool_type && check(cxt, e->e2) == &cxt.bool_type);
            r = &cxt.bool_type;
        }
        void visit(Or_expr* e) {
            assert(check(cxt, e->e1) == &cxt.bool_type && check(cxt, e->e2) == &cxt.bool_type);
            r = &cxt.bool_type;
        }
        void visit(Not_expr* e) {
            assert(check(cxt, e->e1) == &cxt.bool_type);
            r = &cxt.bool_type;
        }
        void visit(Xor_expr* e) {
            assert(check(cxt, e->e1) == &cxt.bool_type && check(cxt, e->e2) == &cxt.bool_type);
            r = &cxt.bool_type;
        }
        void visit(Add_expr* e) {
            assert(check(cxt, e->e1) == &cxt.int_type && check(cxt, e->e2) == &cxt.int_type);
            r = &cxt.int_type;
        }
        void visit(Sub_expr* e) {
            assert(check(cxt, e->e1) == &cxt.int_type && check(cxt, e->e2) == &cxt.int_type);
            r = &cxt.int_type;
        }
        void visit(Mul_expr* e) {
            assert(check(cxt, e->e1) == &cxt.int_type && check(cxt, e->e2) == &cxt.int_type);
            r = &cxt.int_type;
        }
        void visit(Div_expr* e) {
            assert(check(cxt, e->e1) == &cxt.int_type && check(cxt, e->e2) == &cxt.int_type);
            r = &cxt.int_type;
        }
        void visit(Mod_expr* e) {
            assert(check(cxt, e->e1) == &cxt.int_type && check(cxt, e->e2) == &cxt.int_type);
            r = &cxt.int_type;
        }
        void visit(Neg_expr* e) {
            assert(check(cxt, e->e1) == &cxt.int_type);
            r = &cxt.int_type;
        }
        void visit(Les_expr* e) {
            assert(check(cxt, e->e1) == &cxt.int_type && check(cxt, e->e2) == &cxt.int_type);
            r = &cxt.bool_type;
        }
        void visit(Gre_expr* e) {
            assert(check(cxt, e->e1) == &cxt.int_type && check(cxt, e->e2) == &cxt.int_type);
            r = &cxt.bool_type;
        }
        void visit(LOE_expr* e) {
            assert(check(cxt, e->e1) == &cxt.int_type && check(cxt, e->e2) == &cxt.int_type);
            r = &cxt.bool_type;
        }
        void visit(GOE_expr* e) {
            assert(check(cxt, e->e1) == &cxt.int_type && check(cxt, e->e2) == &cxt.int_type);
            r = &cxt.bool_type;
        }
        void visit(Eq_expr* e) {
            assert(check(cxt, e->e1) == &cxt.int_type && check(cxt, e->e2) == &cxt.int_type ||
                  check(cxt, e->e1) == &cxt.bool_type && check(cxt, e->e2) == &cxt.bool_type);
            r = &cxt.bool_type;
        }
        void visit(Neq_expr* e) {
            assert(check(cxt, e->e1) == &cxt.int_type && check(cxt, e->e2) == &cxt.int_type || 
                    check(cxt, e->e1) == &cxt.bool_type && check(cxt, e->e2) == &cxt.bool_type);
            r = &cxt.bool_type;
        }

    };
    V vis(cxt);
    e->accept(vis);
    return vis.r;
}
