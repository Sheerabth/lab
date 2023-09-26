typedef enum {
    T_CONSTANT,
    T_IDENTIFIER,
    T_OPERATION
} NodeType;

typedef struct {
    int value;
} ConstantNode;

typedef struct {
    int index;
} IdentifierNode;

typedef struct {
    int operator;
    int no_of_operands;
    struct NodeStruct* operands[5];
} OperationNode;

typedef struct NodeStruct {
    NodeType type;

    union {
        ConstantNode constant;
        IdentifierNode identifier;
        OperationNode operation;
    };
} Node;