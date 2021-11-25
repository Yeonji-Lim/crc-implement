#include <stdio.h>
#define DDgr 7
#define DGdr 32

typedef unsigned long ulong;

int GetMaxDegr(ulong polynomial);
int main(int argc, char *argv[])
{
    ulong DataWithCRC = 0;
    ulong Generator = 0;
    int opNot_digit;
    int tMax;
    //generator로부터 전달되어지는 인자들을 저장
    fscanf(stdin, "%lu %lu", &DataWithCRC, &Generator);
    //입력받은 위치를 숫자로 저장
    opNot_digit = (int)(((int)argv[1][0]) - 0x30);
    //변화될 전송 데이터의 자릿수를 계산
    tMax = GetMaxDegr(DataWithCRC);
    //데이터의 자릿수 - 바꿀 자릿수의 위치만큼 0x01을 이동시킨 후 전송 데이터와 XOR연산을 함으로써 비트를 변경
    DataWithCRC ^= 0x01 << (tMax - opNot_digit);
    //변화된 데이터를 출력
    fprintf(stdout, "%lu %lu", DataWithCRC, Generator);
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