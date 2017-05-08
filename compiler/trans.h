#ifndef TRANS_H
#define TRANS_H

#include "ast.hpp"
#include "lex.h"


struct Trans {

  		Expr* (get_Bool_expr) { 
			return Expr; 
		}

        Expr* (get_And_expr) { 
			return Expr; 
		}

        Expr* (get_Or_expr) { 
			return Expr; 
		}

        Expr* (get_Not_expr) { 
			return Expr; 
		}

        Expr* (get_Xor_expr) { 
			return Expr; 
		}

        Expr* (get_Int_expre) {
			return Expr; 
		}

        Expr* (get_Add_expr) {
			return Expr; 
		}

        Expr* (get_Sub_expr) {
			return Expr; 
		}

        Expr* (get_Mul_expr) {
			return Expr; 
		}

        Expr* (get_Div_expr) {
			return Expr; 
		}

        Expr* (get_Mod_expr) {
			return Expr; 
		}

        Expr* (get_Neg_expr) {
			return Expr; 
		}

        Expr* (get_Les_expr) {
			return Expr; 
		}

        Expr* (get_Gre_expr) {
			return Expr; 
		}

        Expr* (get_LOE_expr) {
			return Expr; 
		}

        Expr* (get_GOE_expr) {
			return Expr; 
		}

        Expr* (get_Eq_expr) {
			return Expr; 
		}

        Expr* (get_Neq_expr) {
			return Expr; 
		}

        Expr* (get_Cond_expe) {
			return Expr; 
	}
  }
   ;

#endif 
