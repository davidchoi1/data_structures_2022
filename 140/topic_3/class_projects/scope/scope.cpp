#include <iostream>

namespace mtsac {
    const int i{10};    //global scope
}

int i{36};

int main(int argc, char const *argv[])
{
    int i{25};
    std::cout << mtsac::i << " " << i << " " << ::i << std::endl;
    return 0;
}
