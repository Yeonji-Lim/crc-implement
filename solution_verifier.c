#include <stdio.h>
#define DDgr 7
#define DGdr 32
typedef unsigned long ulong;
int Get_Max_Coefficient(ulong _number);
ulong Calculate_CRC(ulong dividend, ulong divisor, ulong dataDgr, ulong genDgr);
int GetMaxDegr(ulong polynomial);
int main()
{
    ulong DataWithCRC = 0;
    ulong Generator = 0;
    ulong CRC = 0;
    int GenDgr, DataDgr;
    fscanf(stdin, "%lu %lu", &DataWithCRC, &Generator);
    printf("DataWithCRC : %lu\n", DataWithCRC);
    printf("Generator : %lu\n", Generator);
    GenDgr = GetMaxDegr(Generator);
    DataDgr = GetMaxDegr(DataWithCRC);
    //CRC_Code 값을 구한다.
    CRC = Calculate_CRC(DataWithCRC, Generator, DataDgr, GenDgr);
    printf("CRC Code = %lu\n", CRC);
    if (CRC == 0)
    {
        printf("Message is correct\n");
        DataWithCRC = DataWithCRC >> GenDgr;
        printf("Transmitted message is '%s'\n", (char *)&DataWithCRC);
        printf("Original input is %lx\n", DataWithCRC);
    }
    else
        printf("Message has Error, uncorrect\n");
}
ulong Calculate_CRC(ulong dividend, ulong divisor, ulong dataDgr, ulong genDgr)
{
    int i;
    for (i = 0; i <= dataDgr; i++)
    {
        if (dividend & (0x1 << (dataDgr - i))) // scan the bit postion of dividend                                                that is set to 1
            dividend = dividend ^ (divisor << ((dataDgr - genDgr) - i));
        if (dividend < divisor)
            break;
    }
    return dividend;
}
//자릿수를 얻는 함수
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