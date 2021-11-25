#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define DDgr 7
#define DGdr 32

typedef unsigned long ulong;

int GetMaxDegr(ulong polynomial);
ulong Calculate_CRC(ulong dividend, ulong divisor, ulong dataDgr, ulong genDgr);

int main()
{
    ulong DataWithCRC = 0;
    ulong Generator = 0;
    ulong CRC = 0;
    int GenDgr, DataDgr;

    fscanf(stdin, "%lu", &DataWithCRC);
    fscanf(stdin, "%lu", &Generator);

    GenDgr = GetMaxDegr(Generator);
    DataDgr = GetMaxDegr(DataWithCRC);

    CRC = Calculate_CRC(DataWithCRC << GenDgr, Generator, DataDgr, GenDgr);
    DataWithCRC = (DataWithCRC << GenDgr) | CRC;
    printf("%lu %lu\n", DataWithCRC, CRC);
    // fprintf(stdout, "%lu %lu\n", DataWithCRC, Generator);
}

ulong Calculate_CRC(ulong dividend, ulong divisor, ulong dataDgr, ulong genDgr)
{
    int i;
    for (i = 0; i <= dataDgr; i++)
    {
        if (dividend & (0x1 << (dataDgr - i)))
        { // scan the bit postion of dividend that is set to 1
            dividend = dividend ^ (divisor << ((dataDgr - genDgr) - i));
            if (dividend < divisor)
                break;
        }
    }
    return dividend;
}
int GetMaxDegr(ulong polynomial)
{
    int i;
    for (i = DGdr; i >= 0; i--)
    {
        if ((polynomial >> i) & 0x01)
            break;
    }
    return i;
}