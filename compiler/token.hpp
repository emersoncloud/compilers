//Token file to manage all tokens


enum Token_kind {
    EOF_tok, Plus_tok, 
    Minus_tok, Mul_tok,
    Div_tok, Mod_tok, 
    Amp_tok, Or_tok,
    Not_tok, Eq_tok,
    Neq_tok, Lt_tok,
    Gt_tok,  LtEq_tok, 
    GtEq_tok, Qu_tok,
    Colon_tok, LeftParen_tok,
    RightParen_tok, Int_tok,
    Bool_tok, Comm_tok,
    BitLeft_tok, BitRight_tok,
    Xor_tok, Space_tok,

    VarInt_tok, VarBool_tok,

    Semi_tok, 
};

struct Token {
    int kind;
    std::string attribute;
    Token() {}
    Token(Token_kind k, int a)
        :kind(k), attribute(std::to_string(a)) {}
    Token(Token_kind k, std::string str)
        :kind(k), attribute(str) {}
    virtual ~Token() = default;

};

struct Int_token : Token {
    int value;
};
struct Bool_token : Token {
    bool value;
};
