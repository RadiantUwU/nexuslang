#pragma once

#include <memory>
#include <tuple>

#define u_obj_f nObj
#define b_obj_f nObj, nObj
#define t_obj_f nObj, nObj, nObj
#define q_obj_f nObj, nObj, nObj, nObj

#define hash_t unsigned long long

template <typename... Args>
inline hash_t C_hash_objects(Args... args) {
    hash_t hash = 0x345678UL;
    std::tuple<Args...> t(args...);
    for (auto& o : t) {
        char* ob = (char*)&o;
        for (int i = 0; i < sizeof(o); i++) {
            hash ^= ob[i];
            hash *= 0x01000193;
            hash += 97531UL;
        }
    }
    //hash finalizer
    hash ^= hash << 13;
    hash += 97531UL;
    hash ^= hash >> 7;
    hash *= 0x01000193;
    hash += 97531UL;
    return hash;
}

class _nType;
using nType = std::shared_ptr<_nType>;
class _nObj;
using nObj = std::shared_ptr<_nObj>;
class _nObj {
public:
    nType type;
    virtual ~_nObj() = default;
    virtual bool has__dict__() { return false; }
    virtual hash_t safe_hash() const;
    virtual hash_t unsafe_hash() const { return safe_hash(); }
    virtual hash_t shallow_hash() const {
        return C_hash_objects(this);
    }
    bool isObj(nObj o) {
        return this == o.get();
    }

};
class _nType : public _nObj {
public:
    virtual hash_t safe_hash() const;
};
hash_t _nObj::safe_hash() const {
    return C_hash_objects(this);
}

