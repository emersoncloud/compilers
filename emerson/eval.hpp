#include "ast.hpp"
#include "value.hpp"
#include "newtype.hpp"
#include <cassert>

Value eval(Expr* e) {
    struct V: Expr::Visitor {
        Value r;
        Context cxt;
        void visit(Bool_expr* e) { 
            r.kind = Value_kind::bool_val;
            r.data.b = e->val; 
        }
        void visit(Int_expr* e) {
            r.kind = Value_kind::int_val;
            r.data.n = e->val;
        }
        void visit(And_expr* e) { 
            check(cxt, e);
            r.kind = Value_kind::bool_val;
            r.data.b = eval(e->e1).data.b & eval(e->e2).data.b; 
        }
        void visit(Or_expr* e) { 
            r.kind = Value_kind::bool_val;
            r.data.b = eval(e->e1).data.b | eval(e->e2).data.b; 
        }
        void visit(Not_expr* e) { 
            r.kind = Value_kind::bool_val;
            r.data.b = !eval(e->e1).data.b; 
        }
        void visit(Xor_expr* e) {
            r.kind = Value_kind::bool_val;
            r.data.b = eval(e->e1).data.b ^ eval(e->e2).data.b;
        }
        void visit(Add_expr* e) {
            r.kind = Value_kind::int_val;
            r.data.n = eval(e->e1).data.n + eval(e->e2).data.n;

        }
        void visit(Sub_expr* e) {
            r.kind = Value_kind::int_val;
            r.data.n = eval(e->e1).data.n - eval(e->e2).data.n;
        }

        void visit(Mul_expr* e) {
            r.kind = Value_kind::int_val;
            r.data.n = eval(e->e1).data.n * eval(e->e2).data.n;
        }

        void visit(Div_expr* e) {
            r.kind = Value_kind::int_val;
            r.data.n = eval(e->e1).data.n / eval(e->e2).data.n;
        }

        void visit(Mod_expr* e) {
            r.kind = Value_kind::int_val;
            r.data.n = eval(e->e1).data.n % eval(e->e2).data.n;
        }

        void visit(Neg_expr* e) {
            r.kind = Value_kind::int_val;
            r.data.n = 0 - eval(e->e1).data.n;
        }
        void visit(Les_expr *e) {
            r.kind = Value_kind::bool_val;
            r.data.b = eval(e->e1).data.n < eval(e->e2).data.n;
        }
        void visit(Gre_expr *e) {
            r.kind = Value_kind::bool_val;
            r.data.b = eval(e->e1).data.n > eval(e->e2).data.n;
        }
        void visit(LOE_expr *e) {
            r.kind = Value_kind::bool_val;
            r.data.b = eval(e->e1).data.n <= eval(e->e2).data.n;
        }
        void visit(GOE_expr *e) {
            r.kind = Value_kind::bool_val;
            r.data.b = eval(e->e1).data.n >= eval(e->e2).data.n;
        }
        //void visit(Cond_expr *e) {
            //r. kind = Value_kind::bool_val;
            //r.data.b = eval(e->e1) | eval(e->e2) | eval(e->e3);
            //r.data.b = eval(e->e1); 
            //if (r.data.b == false) {
            //    r.data.b = eval(e->e2);
            //}
            //else
    };
    V vis;
    e->accept(vis);
    return vis.r;
}
