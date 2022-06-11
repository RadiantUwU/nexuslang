#pragma once

#include <memory>

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
    std::shared_ptr<void> trueObject;
    std::shared_ptr<void> falseObject;
    std::shared_ptr<void> nullObject;
};
_Interpreter& Interpreter = *_Interpreter::__getInstance();