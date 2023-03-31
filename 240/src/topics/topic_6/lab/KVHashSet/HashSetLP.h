#include "functions.h"
#include "keyvalue_pair.h"
#include "set.h"
#ifndef HASH_SET_LP_H
#define HASH_SET_LP_H



class HashSetLP : public Set<std::string>
{
public:
    
    HashSetLP(std::function<int(std::string)>);

    bool insert(const std::string& name);
    bool erase(const std::string& name);
    const std::string* find(const std::string& name);
    bool contains(const std::string& name);
    size_t size();


private:
    std::function<int(std::string)> h1;
    KVPair<std::string, int>* itemArray{new KVPair<std::string, int>[DEFAULT_SIZE]};
    Status* stateArray{new Status[DEFAULT_SIZE]};
    size_t currentSize;
    size_t itemQty;
    int h2(int);
    void resize();

};

#endif