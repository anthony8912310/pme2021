//
//  main.c
//  pme01
//
//  Created by admin on 2021/5/6.
//

#include <stdio.h>
#include <stdlib.h>
void Permutation(int m, int n, int arr[], int temp[], int sum[]);
void find(int n, char result[], int sum[]);
void Permutation(int m, int n, int arr[], int temp[], int sum[])
{
    int i;
    char tmp[n];
    if(m >= n)
    {
        for (i = 0; i <= n-1; i++)
        {
            sprintf(&tmp[i] , "%d", arr[i]);
        }
//        printf("%s\n", tmp);
        find(n, tmp, sum);
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            if (temp[i] == 0)
            {
                temp[i] = 1;
                arr[m] = i + 1;
                Permutation(m + 1, n, arr, temp, sum);
                temp[i] = 0;
            }
        }
    }
}
void find(int n, char result[], int sum[])
{
    for (int r=1; r<= n; r++) {
        
        if (r==1 && result[0]=='1') {
            sum[r-1]+=1;
            continue;
        }
        int min;
        for (int i=0; i<=r-2; i++) {
            if (i==0) {
                min=result[i];
                continue;
            }
            if(result[i]<min){
                min=result[i];
            }
        }
        for (int j=r-1; j<n; j++) {
            if (result[j]<min) {
                if (result[j]=='1') {
                    sum[r-1]+=1;
                    break;
                }else
                {
                    break;
                }
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    int arr[15], temp[15], n;
    scanf("%d", &n);
    int i, k=1, r;
    for (i = 0; i < n; i++)
        temp[i] = 0;
    int sum[n];
    float tmp, ans;
    for (int i = 0; i < n; i++)
    {
        sum[i]=0;
        k*=i+1;
    }
    Permutation(0, n, arr, temp, sum);
    for (int i = 0; i < n; i++) {
        tmp = (float) sum[i] / (float) k;
        if (i==0 || tmp>ans)
        {
            ans = tmp;
            r = i;
        }
    }
    printf("n=%d r=%d p=%.3f\n", n, r+1, ans);
    return 0;
}
