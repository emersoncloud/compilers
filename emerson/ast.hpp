#ifndef AST_HPP
#define AST_HPP

#include <cassert>

struct Bool_type;
struct Int_type;

struct Bool_expr;
struct And_expr;
struct Or_expr;
struct Not_expr;
struct Xor_expr;

struct Int_expr;
struct Add_expr;
struct Sub_expr;
struct Mul_expr;
struct Div_expr;
struct Mod_expr;
struct Neg_expr;

struct Cond_expr; //conditional statement

enum struct TYPE {
    Int_type,
    Bool_type,
};

struct Type {
    struct Visitor;
    virtual ~Type() = default;
    virtual void accept(Visitor&) {}
};

struct Bool_type : Type { };
struct Int_type : Type { };

struct Expr {
    struct Visitor;
    virtual ~Expr() = default;
    virtual void accept(Visitor&) = 0;
};

struct Expr::Visitor {
    virtual void visit(Bool_expr*) = 0;
    virtual void visit(And_expr*) = 0;
    virtual void visit(Or_expr*) = 0;
    virtual void visit(Not_expr*) = 0;
    virtual void visit(Xor_expr*) = 0;
    virtual void visit(Int_expr*) = 0;
    virtual void visit(Add_expr*) = 0;
    virtual void visit(Sub_expr*) = 0;
    //virtual void visit(Mul_expr*) = 0;
    //virtual void visit(Div_expr*) = 0;
    //virtual void visit(Mod_expr*) = 0;
    //virtual void visit(Neg_expr*) = 0;
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
//
//struct Mul_expr : Expr {
//    Expr* e1;
//    Expr* e2;
//    Mul_expr(Expr* e1, Expr* e2)
//        :e1(e1), e2(e2) {}
//    void accept(Visitor& v) {
//        return v.visit(this);
//    }
//};
//
//struct Div_expr : Expr {
//    Expr* e1;
//    Expr* e2;
//    Div_expr(Expr* e1, Expr* e2)
//        :e1(e1), e2(e2) {}
//    void accept(Visitor& v) {
//        return v.visit(this);
//    }
//};
//
//struct Mod_expr : Expr {
//    Expr* e1;
//    Expr* e2;
//    Mod_expr(Expr* e1, Expr* e2)
//        :e1(e1), e2(e2) {}
//    void accept(Visitor& v) {
//        return v.visit(this);
//    }
//};
//
//struct Neg_expr : Expr {
//    Expr* e1;
//    Neg_expr(Expr* e1)
//        :e1(e1) {}
//    void accept(Visitor& v) {
//        return v.visit(this);
//    }
//};

//struct Cond_expr : Expr {
//    Expr* e1;
//    Expr* e2;
//    Cond_expr(Expr* e1, Expr* e2)
//        :e1(e1), e2(e2) {}
//    void accept(Visitor& v) {
//        return v.visit(this);
//    }
//};

struct Context {
    Bool_type bool_type;
    Int_type int_type;
};

#endif
