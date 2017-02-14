#include <iostream>

#include "ast.hpp"
#include "eval.hpp"
#include "print.hpp"
#include "type.hpp"

int main() {
    Context ctx;
    {
        Expr * e = new And_expr(new Not_expr(new Bool_expr(true)) , new Bool_expr(false));
        check(ctx, e);
        print(e);
        std::cout << " == " << eval(e).data.b << '\n';

        Expr * en = new Mod_expr(new Int_expr(4), new Int_expr(3));
        check(ctx, e);
        print(en);
        std::cout << " == " << eval(en).data.n << '\n';

        Expr * en2 = new Mul_expr(new Int_expr(3), new Int_expr(3));
        check(ctx, e);
        print(en2);
        std::cout << " == " << eval(en2).data.b << '\n';

        Expr * enp = new Neq_expr(new Bool_expr(3), new Bool_expr(3));
        check(ctx, enp);
        print(enp);
        std::cout << " == " << eval(enp).data.b << '\n';
        
    }

}
