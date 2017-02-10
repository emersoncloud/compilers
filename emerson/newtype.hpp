#include <iostream>
#include "ast.hpp"

Type* check(Context& cxt, Expr* e) {
    struct V : Expr::Visitor {
        Context& cxt;
        Type* r;
        V(Context& c) : cxt(c) { }

        void visit(Bool_expr* e) {
            r = &cxt.bool_type;
        }

        void visit(And_expr* e) {
            //if(e->type) {
            //    r = e->type;
            //}
            if(check(e->e1) == &cxt.bool_type && check(e->e2) == &cxt.bool_type) {
                r = &cxt.bool_type;
            }
            //e->type = r;
        }
        void visit(Or_expr* e) {
            if(check(e->e1) == &cxt.bool_type && check(e->e2) == &cxt.bool_type) {
                r = &cxt.bool_type;
            }
        }
        void visit(Not_expr* e) {
            if(check(e->e1) == &cxt.bool_type) {
                r = &cxt.bool_type;
            }
        }
        void visit(Xor_expr* e) {
            if(check(e->e1) == &cxt.bool_type && check(e->e2) == &cxt.bool_type) {
                r = &cxt.bool_type;
            }
        }
        void visit(Int_expr* e) {
            r = &cxt.int_type;
        }
        void visit(Add_expr* e) {
            if(check(e->e1) == &cxt.int_type && check(e->e2) == &cxt.int_type) {
                r = &cxt.int_type;
            }
        }

        void visit(Sub_expr* e) {
            if(check(e->e1) == &cxt.int_type && check(e->e2) == &cxt.int_type) {
                r = &cxt.int_type;
            }
        }
        void visit(Mul_expr* e) {
            if(check(e->e1) == &cxt.int_type && check(e->e2) == &cxt.int_type) {
                r = &cxt.int_type;
            }
        }
        void visit(Div_expr* e) {
            if(check(e->e1) == &cxt.int_type && check(e->e2) == &cxt.int_type) {
                r = &cxt.int_type;
            }
        }
        void visit(Mod_expr* e) {
            if(check(e->e1) == &cxt.int_type && check(e->e2) == &cxt.int_type) {
                r = &cxt.int_type;
            }
        }
        void visit(Neg_expr* e) {
            if(check(e->e1) == &cxt.int_type){
                r = &cxt.int_type;
            }
        }
        void visit(Les_expr* e) {
            if(check(e->e1) == &cxt.int_type && check(e->e2) == &cxt.int_type) {
                r = &cxt.bool_type;
            }
        }
        void visit(Gre_expr* e) {
            if(check(e->e1) == &cxt.int_type && check(e->e2) == &cxt.int_type) {
                r = &cxt.bool_type;
            }
        }
        void visit(LOE_expr* e) {
            if(check(e->e1) == &cxt.int_type && check(e->e2) == &cxt.int_type) {
                r = &cxt.bool_type;
            }
        }
        void visit(GOE_expr* e) {
            if(check(e->e1) == &cxt.int_type && check(e->e2) == &cxt.int_type) {
                r = &cxt.bool_type;
            }
        }

    };
    V vis(cxt);
    e->accept(vis);
    return vis.r;
}

