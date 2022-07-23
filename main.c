#include <stdio.h>

int main (){
    int a;

    long long b = (long long)&a;
    printf("%x\n", -234);
    printf("%x\n", -15);
    printf("%x\n", 234);

    printf("%p\n", &"ded");
    printf("%p\n", &a);
    printf("%lld\n", b);
}