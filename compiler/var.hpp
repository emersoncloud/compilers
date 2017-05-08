#ifndef VAR_H
#define VAR_H


struct var {
Expr * variable;
string name;
Expr * v;
var(string name, Expr* v):
	name(name), v(v) { 

}


//TODO make for functions as well as variables




#endif