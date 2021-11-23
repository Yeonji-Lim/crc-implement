#include <stdio.h>

int main() {
    int a, b;
    fscanf(stdin, "%d", &a);
    fscanf(stdin, "%d", &b);

    fprintf(stdout, "%d %d", a, b);
    return 0;
}