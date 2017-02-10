#include "ast.hpp"
#include "value.hpp"

Value eval(Expr* e) {
    struct V : Expr::Visitor {
        Value r;
        void visit(Bool_expr* e) {
        }
    };
    V vis;
    e->accept(vis);
    return vis.r;
}
