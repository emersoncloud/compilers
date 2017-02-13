#Emerson Cloud
--------------
#Compiler Design - Homework 1

###Internal language respresentation for a small expression language 

The language has two kinds of types; integers and boolean values, and are defined in `ast.hpp`.

The language also defines expressions which are built on top of these two basic types, and are also 
defined in `ast.hpp`.

The base `Type` class holds a visitor struct `Visitor` and a single member function `virtual
void accept(Visitor&) {}` that accepts a visitor object by reference to perform operations.


