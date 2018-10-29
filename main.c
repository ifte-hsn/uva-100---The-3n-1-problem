#include <stdio.h>
#include <stdlib.h>
long long size = 100000000;
long long cache[100000000];
int cycle(long long m)
{
    int i = 1;
    if(m == 1){
        return 1;
    }
    while(m!=1)
    {
        if(m < size && cache[m] != 0)
        {
            i =  (i-1)+cache[m];
            return i;
        }
        if(m%2 == 0)
        {
            m = m/2;
            i++;
        }
        else
        {
            m = (3*m+1)/2;
            i = i+2;
        }
    }
    return i;
}

int main()
{
    long long val1;
    long long val2;
    long long m,n;
    long long temp;
    long long i;
    while(scanf("%lld%lld",&val1,&val2)==2)
    {
        if(val1 ==0 || val2 == 0){
            return 0;
        }
        m = val1;
        n = val2;
        if(m > n)
        {
            temp = m;
            m = n;
            n = temp;
        }
        int max = 0;
        for(i =m; i <= n; i++)
        {
            temp = cycle(i);
            if(i < size)
            {
                    cache[i] = temp;
            }
            if(temp > max)
                max = temp;
        }
        printf("%lld %lld %d\n",val1, val2, max);
    }
    return 0;
}
