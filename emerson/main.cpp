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

        Expr * en = new Mod_expr(new Int_expr(4), new Int_expr(3));
        print(en);
        std::cout << " == " << eval(en).data.n << '\n';

        Expr * en2 = new Mul_expr(new Int_expr(3), new Neg_expr(new Int_expr(3)));
        print(en2);
        std::cout << " == " << eval(en2).data.b << '\n';
    }

}
