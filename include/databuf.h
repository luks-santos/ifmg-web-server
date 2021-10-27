#ifndef DATABUF_H
#define DATABUF_H
#include <string.h>
#define maxSizeRecv 4090

class databuf
{
    public:
        databuf();
        virtual ~databuf();
        char* getDataChar();
        int getBufflen();
        int getMaxSizeRecv();
        void setBufflen(int bufflen);
    private:
        char dataChar[maxSizeRecv];
        int bufflen;
};

#endif // DATABUF_H
