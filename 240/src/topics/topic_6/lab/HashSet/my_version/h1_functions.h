union u
{
    double d;
    uint64_t i;
};

int h1Int(int k)
{
    return k;                                                           // return int
}

int h1UInt(uint64_t k)
{
    return static_cast<int>((k >> 32 ) + k);                            // turn 64 bit into 32 bit integer
}

int h1Double(double k)
{
    uint64_t* ki{reinterpret_cast<uint64_t*>(&k)};
    return h1UInt(*ki);
}

int h1String(const std::string& k)
{
    int hash{0};
    const int factor{31};

    for (size_t i{0}; i < k.length(); ++i)
    {
        hash = factor * hash + k[i];
    }

    return hash;
}