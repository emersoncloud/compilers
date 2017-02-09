#include <iostream>

#include "ast.hpp"
#include "eval.hpp"
#include "print.hpp"

int main() {
    Context ctx;
    {
        Expr * e = new Or_expr(new Not_expr(new Bool_expr(false)) , new Bool_expr(false));
        print(e);
        std::cout << " == " << eval(e).data.b << '\n';
    }

}
