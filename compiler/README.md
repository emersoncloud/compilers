#Emerson Cloud and Russell Ratcliffe - Compiler Design


#How to run
1.	Clone repository
2.	cd calculator
3.	mkdir build
4.	cd build
5.	cmake ..
6.	make
7.	./calc


#Overview


##Objects
This language provides facilities that operate on an object and their values. It does not provide any type of direct access to raw storage. Therefore, it is not possible to reinterpret an integer object as a sequence of bytes. In this compiler, an object is defined as a region of storage that is created by a variable declaration or made as a result of a value computation. A program is able to destroy, references, access, create, and modify objects. Objects called stored objects are objects that are created by a declaration. Each stored object has a memory location that may be used to refer to that specific object. Each object that is created by a declaration will have an automatic storage duration. These objects will last until the block statement where there were created exits. Then these objects are destroyed. Multiple objects are able to use the same storage for a variable. Any type of object that is created by a computer are known as temporary objects. Temporary objects are not stored.

##Types
There are a few  types supported by this language. The bool type describes the values true and false. The int type describes any integer values between -(2^32) and 2^32. 
The bool and int types are examples of object types. There is also a function type. The type (int, int) -> bool is the type of all functions that take two int arguments and return a bool value. In this example, the two ints are the parameter types of the function, and bool is the return type of the function. In addition there is a reference type. The values of a reference type are the memory locations of stored objects of type t. 


##Translation 

###Parser
 The parser should consider two main cases of parsing, a declaration expression eg. var int x = 5 as well as expression statements eg. y + 10. Each statement is a complete set of expressions and is capped with a semi-colon. This statement becomes its own AST to be evaluated during the back-end portion of our compiler. The new expression to parse from homework 4 is the function signature, that defines the function type with a function statement. 
Statements are executed as part of a function and statements produce side effects. 
The Parser is defined in parser.hpp. The Parser in this context is an object with a member variable as the sequence of tokens from the lexer. It has one constructor that takes a sequence of tokens and sets its member vector to contain each of those tokens. The class also defines several helper functions to be used by other functions in this class. peek(), lookahead(), consume(), match() and match_if() are all examples of these helper functions. Most of these functions are parallels of the ones found in the lexer. This is because the lexing of characters to create tokens is a very similar process of parsing those tokens into statements.
One of the most used functions, match_if(token_kind k) has a special behavior. This function only consumes a new token if it matches the type of token passed to the function. This allows one to create if else statements that only get caught if the next token is the token you are looking for.
The entry point into the parser is through a function parse(). This function creates a vector to hold all of the expression sequences pulled out of the tokens, and returns nothing. When the expression sequence is created the function expression_seq is called. This creates a new expression as long as there are tokens still in the token vector.
When a new expression is created, the function expression() is called and followed by a call to the match function to make sure the character following the expression is a semi-colon.
Then we follow down the calls of different expression functions. Each of these functions attempts to match the next character to what it needs to create that type of expression. For example the multiplicative_expression() tries to match the next token with a Mul_tok or a Div_tok or a Remainder_Tok (* or / or %). Else it breaks out of the matching while loop and the function.
The primary_expression() function matches the next token to one of the primary expressions such as true, false, or an integer. These represent the base expressions all of the other expressions are built from.
Finally the resulting expression is returned to the expression sequence to be evaluated and manipulated by the back-end of our compiler.
The front end to the lexer and testing is contained in parsemain.cpp. Here input is taken in line by line and then put through the lexer and the tokens created are outputted. A while loop reads in each line from std::cin and creates a Lexer object with the line. Then in a while loop the tokens are created from the lexer.next()function and appended to a toks vector for holding.
Then the tokens from the vector are fed into the parser which creates the ASTs from the vector of tokens.


##Things we didn’t quite get to
We would have liked to implement code generation, although we ran out of time. The idea behind code generation is to take the AST and transform each expression and statement into the corresponding JVM code. This would be done through a similar translation scheme to parsing and evaluating, but the output is now JVM or LLVM. 
