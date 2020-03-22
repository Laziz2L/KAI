#include <stdlib.h>
#include <stdio.h>
#define ull unsigned long long
int check(ull val);
int main(int argc, char const *argv[])
{
    ull N = atoll(argv[1]);
    ull counter = 0;
    int curValue = 0;


    while(counter != N){
        //printf("cur: %d\n",curValue);
        if(check(curValue) != 0)
        {
            counter+=1;
            printf("res %d\n",curValue);
        }
        curValue += 1;
    }

    return 0;
}
ull getReversByte(ull val)
{
    ull byteVal = 0;
    for(int i = 0; i<8; i++)
    {
        byteVal <<= 1;
        byteVal += val%2;
        val >>= 1;
    }
    //printf("%llu", byteVal);
    return byteVal;
}
int check(ull val)
{
    ull firsByte = val%256;
    ull secondByte = getReversByte(val/256);
    //printf("fB %llu sB %llu fB^sB %llu\n ", firsByte, secondByte, firsByte^secondByte);
    if(firsByte == secondByte)
    {
        getReversByte(val/256);
        return 1;
    }
    else
    {
        return 0;
    }
}
