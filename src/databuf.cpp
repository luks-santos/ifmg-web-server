#include "databuf.h"

databuf::databuf()
{
    memset(dataChar, '\0', maxSizeRecv);
    bufflen = 0;
}

databuf::~databuf()
{
}

char* databuf::getDataChar() {
    return dataChar;
}

int databuf::getBufflen() {
    return bufflen;
}

int databuf::getMaxSizeRecv() {
    return maxSizeRecv;
}
void databuf::setBufflen(int bufflen) {
    this->bufflen = bufflen;
}
