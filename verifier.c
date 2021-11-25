#include <stdio.h>

//해당 값의 비트 사이즈를 계산한다.
int bitSize (int x) {
    int s = 0;
    while(x != 0) {
        x = x >> 1;
        s++;
    }
    return s;
}

//CRC 알고리즘을 수행하여 Remainder를 반환한다.
int CRCalgo (int Mk, int G, int nk, int k) {
    while(nk > -1){
        // printf("Mk = %lu, nk = %d\n", Mk, nk);

        //맨 앞자리가 1인 경우 연산을 수행하고 아닌 경우는 다음 자리수로 넘어간다.
        if(Mk & (1 << (nk-1))){
            //XOR 연산을 수행한다.
            Mk = Mk ^ (G << (nk - k));
        }
        nk--;

        //MK에는 연산을 진행함에 따라 다음 XOR연산에 사용될 값이 들어가고
        //이 값이 Generator보다 작아지면 나머지이므로 반환한다.
        if(Mk < G) break;
    }
    return Mk;
}

int main() {
    int T, G, R;        //차례로 받은 메시지, Generator, Remainder를 저장
    int t, k;           //T, G의 bit size 저장

    //입력받은 파일로 부터 메시지와 Generator를 입력받는다.
    fscanf(stdin, "%d %d", &T, &G);
    printf("Transmitted Frame : %d\n", T);
    printf("Generator : %d\n", G);

    //메시지와 Generator의 비트 사이즈를 계산한다.
    t = bitSize(T);
    k = bitSize(G);

    //Remainder를 구한다.
    R = CRCalgo(T, G, t, k);
    printf("Remainder : %d\n", R);

    //계산한 Remainder가 0이라면 error가 없는 것으로 간주한다.
    if(R == 0) {
        printf("No error detected\n");
    } else {
        printf("Error detected\n");
    }
}