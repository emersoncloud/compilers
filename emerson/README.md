#Emerson Cloud
--------------
#Compiler Design - Homework 1
###Internal language respresentation for a small expression language 

##Overview
This language has functionalily to represent basic data types and operations on those data
types through expressions. These expressions and types allow for the language to evaluate 
complex expressions. THe expressions are stored in an abstract syntax tree or AST. Through the visitor
pattern we can perform operations on the expressions defined by the AST. The opperations defined in 
this language are print, evaluate, and type check.

#How to run
1. Clone repository
2. mkdir build
3. cd build
4. cmake ..
5. make
6. ./bool

#Implementation
The language has two kinds of types; integers and boolean values, and are defined in `ast.hpp`.

The language also defines expressions which are built on top of these two basic types, and are also 
defined in `ast.hpp`.

The base `Type` class holds a visitor struct `Visitor` and a single member function `virtual
void accept(Visitor&) {}` that accepts a visitor object by reference to perform various operations. 
Both `Bool_type` and `Int_type` inherit from `Type`. 

The base `Expr` class has the same members as the `Type` base class but includes a `Type *ty` to 
hold the type of the epression to be used for type checking.

The `Expr::Visitor` defines all of the pure virtual visitor fucntions that must be overridden by
the derived classes. These functions take as arguments all of the kinds of expressions defined
in the language. This allows the visitor to call the correct function by type.


