#include <stdio.h>

//해당 값의 비트 사이즈를 계산한다.
int bitSize (unsigned long x) {git 
    int s = 0;
    while(x != 0) {
        x = x >> 1;
        s++;
    }
    return s;
}

int main(int argc, char* argv[]) {
    int T, G;                   //차례로 보낼 메시지, Generator를 저장
    int t = argv[1][0]-'0';     //반전시키고자하는 비트의 순서를 저장

    //입력받은 파일로 부터 메시지와 Generator를 입력받는다.
    fscanf(stdin, "%d %d", &T, &G);   
    // printf("alter가 받은 Trasmitted Frame, Generator : %lu %lu\n", T, G);
    // printf("Target bit 자리 : %d\n", t);

    //반전을 원하는 비트자리수가 1인 비트값과 메시지를 xor 연산을 하여 메시지의 해당 비트를 반전시킨다.
    T = T ^ (1 << (bitSize(T)-t));

    // printf("비트 반전 후 Transmitted Frame : %lu\n", T);
    fprintf(stdout, "%d %d", T, G);
}