#ifndef AST_HPP
#define AST_HPP
#include <cassert>

//Two types defined in language
struct Bool_type;
struct Int_type;

//Boolean expressions
struct Bool_expr;
struct And_expr;
struct Or_expr;
struct Not_expr;
struct Xor_expr;
struct Cond_expr;

//Integer expressions
struct Int_expr;
struct Add_expr;
struct Sub_expr;
struct Mul_expr;
struct Div_expr;
struct Mod_expr;
struct Neg_expr;
struct Les_expr;
struct Gre_expr;
struct LOE_expr;
struct GOE_expr;

//General expressions
struct Eq_expr;
struct Neq_expr;


enum struct TYPE {
    Int_type,
    Bool_type,
};

//Base Type class
struct Type {
    struct Visitor;
    virtual ~Type() = default;
    virtual void accept(Visitor&) {}
};

struct Bool_type : Type { };
struct Int_type : Type { };

//Base Expression class
struct Expr {
    struct Visitor;
    Type *ty = nullptr;
    virtual ~Expr() = default;
    virtual void accept(Visitor&) = 0;
};

struct Context {
    Bool_type bool_type;
    Int_type int_type;
};

//Definition of Expression Visitor class
struct Expr::Visitor {
    virtual void visit(Bool_expr*) = 0;
    virtual void visit(And_expr*) = 0;
    virtual void visit(Or_expr*) = 0;
    virtual void visit(Not_expr*) = 0;
    virtual void visit(Xor_expr*) = 0;
    virtual void visit(Int_expr*) = 0;
    virtual void visit(Add_expr*) = 0;
    virtual void visit(Sub_expr*) = 0;
    virtual void visit(Mul_expr*) = 0;
    virtual void visit(Div_expr*) = 0;
    virtual void visit(Mod_expr*) = 0;
    virtual void visit(Neg_expr*) = 0;
    virtual void visit(Les_expr*) = 0;
    virtual void visit(Gre_expr*) = 0;
    virtual void visit(LOE_expr*) = 0;
    virtual void visit(GOE_expr*) = 0;
    virtual void visit(Eq_expr*) = 0;
    virtual void visit(Neq_expr*) = 0;
    virtual void visit(Cond_expr*) = 0;
};                     

struct Bool_expr : Expr {
    bool val;
    Bool_expr(bool b) : val(b) {}
    void accept(Visitor& v) {
        return v.visit(this);
    }
};

struct Int_expr : Expr {
    int val;
    Int_expr(int i) : val(i) {}
    void accept(Visitor& v) {
        return v.visit(this);
    }
};

struct And_expr : Expr {
    Expr* e1;
    Expr* e2;
    And_expr(Expr* e1, Expr* e2) 
        : e1(e1), e2(e2) { }
    void accept(Visitor& v) {
        return v.visit(this);
    }
};

struct Or_expr : Expr {
    Expr* e1;
    Expr* e2;
    Or_expr(Expr* e1, Expr* e2) 
        : e1(e1), e2(e2) { }
    void accept(Visitor& v) {
        return v.visit(this);
    }
};

struct Not_expr : Expr {
    Expr* e1;
    Not_expr(Expr* e1) 
        : e1(e1) { }
    void accept(Visitor& v) {
        return v.visit(this);
    }
};
struct Xor_expr : Expr {
    Expr* e1;
    Expr* e2;
    Xor_expr(Expr* e1, Expr* e2)
        :e1(e1), e2(e2) {}
    void accept(Visitor& v) {
        return v.visit(this);
    }
};
struct Cond_expr : Expr {
    Expr* e1;
    Expr* e2;
    Expr* e3;
    Cond_expr(Expr* e1, Expr* e2, Expr* e3)
        :e1(e1), e2(e2), e3(e3) {}
    void accept(Visitor& v) {
        return v.visit(this);
    }
};

struct Add_expr : Expr {
    Expr* e1;
    Expr* e2;
    Add_expr(Expr* e1, Expr* e2)
        :e1(e1), e2(e2) {}
    void accept(Visitor& v) {
        return v.visit(this);
    }
};
struct Sub_expr : Expr {
    Expr* e1;
    Expr* e2;
    Sub_expr(Expr* e1, Expr* e2)
        :e1(e1), e2(e2) {}
    void accept(Visitor& v) {
        return v.visit(this);
    }
};

struct Mul_expr : Expr {
    Expr* e1;
    Expr* e2;
    Mul_expr(Expr* e1, Expr* e2)
        :e1(e1), e2(e2) {}
    void accept(Visitor& v) {
        return v.visit(this);
    }
};

struct Div_expr : Expr {
    Expr* e1;
    Expr* e2;
    Div_expr(Expr* e1, Expr* e2)
        :e1(e1), e2(e2) {}
    void accept(Visitor& v) {
        return v.visit(this);
    }
};

struct Mod_expr : Expr {
    Expr* e1;
    Expr* e2;
    Mod_expr(Expr* e1, Expr* e2)
        :e1(e1), e2(e2) {}
    void accept(Visitor& v) {
        return v.visit(this);
    }
};

struct Neg_expr : Expr {
    Expr* e1;
    Neg_expr(Expr* e1)
        :e1(e1) {}
    void accept(Visitor& v) {
        return v.visit(this);
    }
};

struct Les_expr : Expr {
    Expr* e1;
    Expr* e2;
    Les_expr(Expr*e1, Expr *e2)
        :e1(e1), e2(e2) {}
    void accept(Visitor& v){
        return v.visit(this);
    }
};
struct Gre_expr : Expr {
    Expr* e1;
    Expr* e2;
    Gre_expr(Expr*e1, Expr *e2)
        :e1(e1), e2(e2) {}
    void accept(Visitor& v){
        return v.visit(this);
    }
};
struct LOE_expr : Expr {
    Expr* e1;
    Expr* e2;
    LOE_expr(Expr*e1, Expr *e2)
        :e1(e1), e2(e2) {}
    void accept(Visitor& v){
        return v.visit(this);
    }
};
struct GOE_expr : Expr {
    Expr* e1;
    Expr* e2;
    GOE_expr(Expr*e1, Expr *e2)
        :e1(e1), e2(e2) {}
    void accept(Visitor& v){
        return v.visit(this);
    }
};

struct Eq_expr : Expr {
    Expr* e1;
    Expr* e2;
    Eq_expr(Expr*e1, Expr *e2)
        :e1(e1), e2(e2) {}
    void accept(Visitor& v){
        return v.visit(this);
    }
};

struct Neq_expr : Expr {
    Expr* e1;
    Expr* e2;
    Neq_expr(Expr*e1, Expr *e2)
        :e1(e1), e2(e2) {}
    void accept(Visitor& v){
        return v.visit(this);
    }
};

#endif
