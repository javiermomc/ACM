/*
 * ACM IP 3093
 * Javier Mondragon Martin del Campo
 * Toluca, Estado de Mexico
 * 31/08/2017
 */

#include <stdio.h>
#include <math.h>
#include <cstdlib>

int main() {
    int cases, bit, pos=0, bit1=0, bit2=0, bit3=0, bit4=0;
    scanf("%d", &cases);
    char inputUser[33];
    char *input = (char*)malloc(cases*32* sizeof(char));
    for(int i=cases-1; i>=0; i--) {
        scanf("%s", &inputUser);
        for(int i1 =0; i1<32; i1++){
            input[i1+i*32]=inputUser[i1];
        }
    }
    int init = -1;
    for(int i=cases*32; i>=0; i--){
        if(init==-1){
            init=i-32;
        }
        bit = input[i]-'0';
        if(bit==1){
            if(i<=7+init){
                pos=7-i+init;
                bit1+=powf(2.0, pos);
            } else if(i<=15+init){
                pos=15-i+init;
                bit2+=powf(2.0, pos);
            } else if(i<=23+init){
                pos=23-i+init;
                bit3+=powf(2.0, pos);
            } else if(i<=31+init){
                pos=31-i+init;
                bit4+=powf(2.0, pos);
            }
        }
        if(i<=init){
            init-=32;
            printf("%d.%d.%d.%d\n", bit1,bit2, bit3, bit4);
            bit1=0; bit2=0; bit3=0; bit4=0;
        }
    }
    return 0;
}