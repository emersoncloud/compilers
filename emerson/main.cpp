#include <iostream>

#include "ast.hpp"
#include "eval.hpp"
#include "print.hpp"
#include "type.hpp"

int main() {
    Context ctx;
    {
        Expr * e1 = new And_expr(new Not_expr(new Bool_expr(true)) , new Bool_expr(false));
        check(ctx, e1);
        print(e1);
        std::cout << " == " << eval(e1).data.b << '\n';

        Expr * e2 = new And_expr(new Bool_expr(true) , new Bool_expr(false));
        check(ctx, e2);
        print(e2);
        std::cout << " == " << eval(e2).data.b << '\n';

        Expr * e3 = new Or_expr(new Bool_expr(true), new Bool_expr(false));
        check(ctx, e3);
        print(e3);
        std::cout << " == " << eval(e3).data.b << '\n';
        
        Expr * e4 = new Xor_expr(new Bool_expr(true) , new Bool_expr(true));
        check(ctx, e4);
        print(e4);
        std::cout << " == " << eval(e4).data.b << '\n';

        Expr * e5 = new Add_expr(new Int_expr(5) , new Int_expr(6));
        check(ctx, e5);
        print(e5);
        std::cout << " == " << eval(e5).data.n << '\n';

        Expr * e5n = new Add_expr(new Neg_expr(new Int_expr(5)) , new Int_expr(6));
        check(ctx, e5n);
        print(e5n);
        std::cout << " == " << eval(e5n).data.n << '\n';

        Expr * e6 = new Sub_expr(new Int_expr(5) , new Int_expr(6));
        check(ctx, e6);
        print(e6);
        std::cout << " == " << eval(e6).data.n << '\n';

        Expr * e7 = new Mul_expr(new Int_expr(5) , new Int_expr(6));
        check(ctx, e7);
        print(e7);
        std::cout << " == " << eval(e7).data.n << '\n';

        Expr * e8 = new Div_expr(new Int_expr(25) , new Int_expr(4));
        check(ctx, e8);
        print(e8);
        std::cout << " == " << eval(e8).data.n << '\n';


        Expr * e9 = new Mod_expr(new Int_expr(4), new Int_expr(3));
        check(ctx, e9);
        print(e9);
        std::cout << " == " << eval(e9).data.n << '\n';

        Expr * e10 = new Les_expr(new Int_expr(8), new Int_expr(3));
        check(ctx, e10);
        print(e10);
        std::cout << " == " << eval(e10).data.b << '\n';

        Expr * e11 = new Gre_expr(new Int_expr(8), new Int_expr(3));
        check(ctx, e11);
        print(e11);
        std::cout << " == " << eval(e11).data.b << '\n';

        Expr * e12 = new LOE_expr(new Int_expr(3), new Int_expr(3));
        check(ctx, e12);
        print(e12);
        std::cout << " == " << eval(e12).data.b << '\n';

        Expr * e13 = new Les_expr(new Int_expr(8), new Int_expr(9));
        check(ctx, e13);
        print(e13);
        std::cout << " == " << eval(e13).data.b << '\n';

        Expr * e14 = new Neq_expr(new Bool_expr(true), new Bool_expr(true));
        check(ctx, e14);
        print(e14);
        std::cout << " == " << eval(e14).data.b << '\n';

        Expr * e15 = new Eq_expr(new Bool_expr(true), new Bool_expr(true));
        check(ctx, e15);
        print(e15);
        std::cout << " == " << eval(e15).data.b << '\n';

        Expr * e16 = new Cond_expr(new Bool_expr(true), new Bool_expr(false), new Bool_expr(true));
        check(ctx, e16);
        print (e16);
        std::cout << " == " << eval(e16).data.b << '\n';
    }
}
