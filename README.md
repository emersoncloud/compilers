#Emerson Cloud
--------------
#Compiler Design - Homework 1
###Internal language respresentation for a small expression language 

#Overview
This language has functionalily to represent basic data types and operations on those data
types through expressions. These expressions and types allow for the language to evaluate 
complex expressions. The expressions are stored in an abstract syntax tree or AST. Through 
the visitor
pattern we can perform operations on the expressions defined by the AST. The opperations 
defined in this language are print, evaluate, and type check.

The visitor pattern was used to ensure seperation of concerns between the definition of 
the types and expressions and the algorithms that operate on these objects.

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

To evaluate an expression the `eval` function is called, which is defined in
`eval.hpp`. `eval` takes an expression and returns a value. The function defines 
a struct V which inherits from `Expr::Visitor`. 
The `struct V` has a `Value` object as defined in `value.hpp`. This object has
both a kind and a data object. `Value` can hold an integer type or a bool type object. 
`Value` also has visit functions for each data type. The visit function takes an
expression pointer and assigns the type and evaluates the expression.

The `print` function as defined in `print.hpp` has a very similiar structure to `eval`
with a different output. Instead of returning a value print outputs the expression 
in a human readable format. The first componenet of `print.hpp` is a function to 
determine whether or not the expression should be printed with parenthesis. Secondly
the `print` function prints the expression.

Finally `check` defined in `type.hpp` checks an expression to ensure proper typing 
before the expression is evaluated.

