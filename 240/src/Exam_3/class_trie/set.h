#ifndef SET
#define SET

template<typename T>
struct Set 
{
    // insert item into set, returns false if the item already exists
    virtual bool insert(const T&) = 0;

    // remove item from the set, returns false if the item is not contained
    virtual bool erase(const T& item) = 0;

    // if set contains item then return true or false otherwise
    virtual bool contains(const T& item) = 0;
};

#endif /* SET */
