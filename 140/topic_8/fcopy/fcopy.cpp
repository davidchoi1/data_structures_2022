    #include "fcopy.h"
    
    void FCopy::operator()(const std::string &srcFilename, const std::string &dstFilename)
    {
        char buffer[4096];
        std::ifstream src(srcFilename, std::ios::in | std::ios::binary);
        if (!src)
            throw InputFileOpeningError();

        std::ofstream dst(dstFilename, std::ios::out | std::ios::binary);
        if(!dst)
            throw OutputFileOpeningError();

        while (src)
        {
            src.read(buffer, sizeof(buffer));
            dst.write(buffer, src.gcount());
        }

        src.close();
        dst.close();
    }