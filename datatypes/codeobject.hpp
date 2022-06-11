#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
namespace CodeObjectDataTypes {
    using std::string;
    using std::vector;
    using std::unordered_map;
    enum class TokenType {
        NONE,
        TOKEN,
        OPERATOR,
        KEYWORD,
        FUNCTION_NAME,
        FUNCTION_ARGS,
        START_CODEBLOCK,
        END_CODEBLOCK,
        END,
        STRING_LITERAL,
        INTEGER_LITERAL,
        NUMBER_LITERAL,
        BOOLEAN_LITERAL,
        NULL_LITERAL,
        START_INDEX,
        END_INDEX,
        START_GROUP,
        END_GROUP,
        START_TABLE,
        END_TABLE,
        DELIMITER
    };
    struct Token final {
        TokenType type;
        string value;
        Token(TokenType type = TokenType::NONE, string value = "") : type(type), value(value) {}
        Token() : type(TokenType::NONE), value("") {}
    };
    enum class InstructionType {
        NOOP,
        ADD,
        SUB,
        MUL,
        DIV,
        MOD,
        POW,
        AND,
        OR,
        XOR,
        NOT,
        BOOLEAN_AND,
        BOOLEAN_OR,
        BOOLEAN_XOR,
        BOOLEAN_NOT,
        EQUAL,
        NOT_EQUAL,
        GREATER_THAN,
        GREATER_THAN_OR_EQUAL,
        LESS_THAN,
        LESS_THAN_OR_EQUAL,
        ASSIGN,
        ASSIGN_ADD,
        ASSIGN_SUB,
        ASSIGN_MUL,
        ASSIGN_DIV,
        ASSIGN_MOD,
        ASSIGN_POW,
        ASSIGN_AND,
        ASSIGN_OR,
        ASSIGN_XOR,
        ASSIGN_NOT,
        ASSIGN_BOOLEAN_AND,
        ASSIGN_BOOLEAN_OR,
        ASSIGN_BOOLEAN_XOR,
        ASSIGN_BOOLEAN_NOT,
        POP_STACK,
        INDEX_POP_STACK,
        MOVE_STACK,
        CLEAR_STACK,
        PUSH_STACK_NONE,
        PUSH_STACK_TRUE,
        PUSH_STACK_FALSE,
        PUSH_STACK_STRING,
        PUSH_STACK_INTEGER,
        PUSH_STACK_NUMBER,
        GETITEM,
        SETITEM,
        DELITEM,
        GETATTR,
        SETATTR,
        DELATTR,
        CALL,
        NEW_FUNCTION
    };
    class Instruction final {
    public:
        InstructionType type;
        vector<Token> args;
    };
    class CodeObject {
    public:
        vector<Instruction> instructions;
        unordered_map<long long, std::shared_ptr<void>> enviroment;
        string functionname;
        vector<string> functionargs;
        vector<std::shared_ptr<void>> stack;
        CodeObject* parent = nullptr;
        CodeObject() noexcept : functionname("__main__") {}
        CodeObject(string functionname,CodeObject* parent) noexcept
        : functionname(functionname), parent(parent) {} 
        vector<std::shared_ptr<void>> run();
    };
};