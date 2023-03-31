#include <iostream>
#include <fstream>

#define BUFFER_SIZE 4096

struct InputFileOpeningError : public std::runtime_error
{
    InputFileOpeningError() : std::runtime_error("Error in open file!") {}
    InputFileOpeningError(const char *msg) : std::runtime_error(msg) {}
};

struct OutputFileOpeningError : public std::runtime_error
{
    OutputFileOpeningError() : std::runtime_error("Error in dest file!") {}
    OutputFileOpeningError(const char *msg) : std::runtime_error(msg) {}
};

class Crypto
{
public:
    Crypto() { }

    void encryptDecrypt(char const* srcFile, char const* otpFile, char const* destFile)
    {
        std::ifstream source(srcFile, std::ios::in | std::ios::binary);
        if(!source)
            throw InputFileOpeningError();
        
        std::ifstream otp(otpFile, std::ios::in | std::ios::binary);
        if(!otp)
            throw InputFileOpeningError("Error opening otp file!");

        std::ofstream dest(destFile, std::ios::binary);
        if(!dest)
            throw OutputFileOpeningError();
        

        while (source)
        {
            source.read(buffer, BUFFER_SIZE);
            otp.read(otpBuffer, BUFFER_SIZE);
            

            for (size_t i{0}; i < source.gcount(); ++i)
            {
                buffer[i] = buffer[i] ^ otpBuffer[i];
            }

            dest.write(buffer, source.gcount());
        }

        source.close();
        otp.close();
        dest.close();
        
    }

private:
    char buffer[BUFFER_SIZE];
    char otpBuffer[BUFFER_SIZE];


};

int main(int argc, char const *argv[])
{

    Crypto cryptographer;

    cryptographer.encryptDecrypt(argv[1], argv[2], argv[3]);

    return 0;
}
