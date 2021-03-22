#include <stdio.h>

#define MAXN 46340
#define MAXP 5000

int primes[MAXP];
int psize;

using namespace std;
void getPrimes(){
    int i, j, isprime;

    psize = 0;
    primes[psize++] = 2;
    for(i = 3; i <= MAXN; i+= 2){
        for(isprime = j = 1; j < psize; j++){
            if(i % primes[j] == 0){
                isprime = 0;
                break;
            }
            if(1.0*primes[j]*primes[j] > i) break;
        }
        if(isprime) primes[psize++] = i;
    }
}

typedef struct{
    int size;
    int f[32];
} Factors;

Factors getPFactor(int n){
    Factors x;
    int i;

    x.size = 0;
    for(i = 0; i < psize; i++){
        while(n % primes[i] == 0){
            x.f[x.size++] = primes[i];
            n /= primes[i];
        }
        if(1.0*primes[i]*primes[i] > n) break;
    }
    if(n > 1){
        x.f[x.size++] = n;
    }
    return x;
}

int main(){
    Factors x;
    int i, n;

    getPrimes();
    while(scanf("%d", &n) == 1 && n > 1){
        x =  getPFactor(n);
        cout << x;
        printf("%d = ", n);
        for(i = 0; i < x.size; i++){
            if(i) printf(" x ");
            printf("%d", x.f[i]);
        }
        printf("\n");
    }
    return 0;
}