#include <fstream>
#include <iostream>

#define BUFFER_SIZE 4096

struct FileError : public std::runtime_error
{
    FileError() : std::runtime_error("Error in file operation") {}
    FileError(const char *msg) : std::runtime_error(msg) {}
};

class Crypter
{
public:
    void crypto(const char *srcFile, const char *otpFile, const char *dstFile)
    {
        std::ifstream src(srcFile, std::ios::in | std::ios::binary);
        if (!src)
            throw FileError("Error in opening source file!");

        std::ifstream otp(otpFile, std::ios::in | std::ios::binary);
        if (!otp)
            throw FileError("Error in opening otp file!");

        std::ofstream dst(dstFile, std::ios::out | std::ios::binary);
        if (!dst)
            throw FileError("Error in opening destination file!");

        while (src)
        {
            src.read(buffer, BUFFER_SIZE);
            otp.read(otpBuffer, BUFFER_SIZE);

            for (size_t i{0}; i < src.gcount(); ++i)
                buffer[i] = buffer[i] ^ otpBuffer[i];
            
            dst.write(buffer, src.gcount());
        }

        src.close();
        otp.close();
        dst.close(); 
    }

private:
    char buffer[BUFFER_SIZE];
    char otpBuffer[BUFFER_SIZE];
};

int main(int argc, char const *argv[])
{
    Crypter crypter;

    crypter.crypto(argv[1], argv[2], argv[3]);
    return 0;
}
