#include <iostream>
#include <unordered_map>


struct Scope_table {

    struct Stack {
        struct Node {

            std::unordered_map <std::string, Decl*> symbol_table;
            Node* prev;
            

        };

        Node* front = nullptr;
        Node* back = nullptr;
        
        void Push();

        void Pop();

        bool is_empty();
    };


    void insertInScope();
    void addScope();
        
    void removeScope();

};
