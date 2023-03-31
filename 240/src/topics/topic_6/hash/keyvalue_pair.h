#ifndef KEYVALUE_PAIR_H
#define KEYVALUE_PAIR_H

template<typename K, typename V>                                                                                // K is type of key and V is type of value
struct KVPair
{
    K key;
    V value;

    KVPair(K key, V value) : key{key}, value{value} { }                                                         // take in key type k and value type v and initialize 

    bool operator<(const KVPair<K,V>& other) { return key < other.key; }                                        // overload operator so as to create
    bool operator>=(const KVPair<K,V>& other) { return !(*this < other); }
    bool operator>(const KVPair<K,V>& other) { return key > other.key; }
    bool operator<=(const KVPair<K,V>& other) { return !(*this > other); }

    bool operator==(const KVPair<K,V>& other) { return key == other.key; }
    bool operator!=(const KVPair<K,V>& other) { return !(*this == other); }
};

#endif