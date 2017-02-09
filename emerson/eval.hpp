#include "ast.hpp"

bool eval(Expr* e) {
    struct V: Expr::Visitor {
        bool r;
        void visit(Bool_expr* e) { 
            r = e->val; 
        }
        void visit(And_expr* e) { 
            r = eval(e->e1) & eval(e->e2); 
        }
        void visit(Or_expr* e) { 
            r = eval(e->e1) | eval(e->e2); 
        }
        void visit(Not_expr* e) { 
            r = !eval(e->e1); 
        }
        void visit(Xor_expr* e) {
            r = eval(e->e1) ^ eval(e->e2);
        }
        void visit(Int* e) {
            r = e->val;
        }
        void visit(Xor_expr* e) {
            r = eval(e->e1) ^ eval(e->e2);

        }
        void visit(Xor_expr* e) {
            r = eval(e->e1) ^ eval(e->e2);

        }
        void visit(Xor_expr* e) {
            r = eval(e->e1) ^ eval(e->e2);

        }
        void visit(Xor_expr* e) {
            r = eval(e->e1) ^ eval(e->e2);

        }
    };
    V vis;
    e->accept(vis);
    return vis.r;
}
