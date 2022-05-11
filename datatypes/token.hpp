#pragma once
#include<string>
enum TokenType {
    NONE,
    TOKEN,
    GROUP_START,
    GROUP_END,
    LIST_START,
    LIST_END,
    INDEX_START,
    INDEX_END,
    GETITEM,
    SETITEM,
    GETATTR,
    SETATTR,
    
};