#pragma once
#include "gc.hpp"
class CodeObject;
class _Interpreter {
private:
    _Interpreter() {};
    static _Interpreter instance;
    _Interpreter(const _Interpreter&) = delete;
    _Interpreter& operator=(const _Interpreter&) = delete;
public:
    static _Interpreter* __getInstance() {
        return &instance;
    }
    CodeObject* mainfunction;
    gc::Generic trueObject;
    gc::Generic falseObject;
    gc::Generic nullObject;
};
_Interpreter& Interpreter = *_Interpreter::__getInstance();