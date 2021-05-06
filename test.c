//
//  main.c
//  pme01
//
//  Created by admin on 2021/5/6.
//

#include <stdio.h>
#include <stdlib.h>
void Permutation(int m, int n, int arr[], int temp[], char result[]);
void find(int n, char result[]);
void Permutation(int m, int n, int arr[], int temp[], char result[])
{
    int i;
    char tmp;
    if(m >= n)
    {
        for (i = 0; i <= n-1; i++)
        {
            tmp = arr[i]+'0';
            result[i] = tmp;
            printf("%d", arr[i]);
        }
        printf("\n");
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            if (temp[i] == 0)
            {
                temp[i] = 1;
                arr[m] = i + 1;
                Permutation(m + 1, n, arr, temp, result);
                temp[i] = 0;
            }
        }
    }
}
void find(int n, char result[])
{
//    printf("%s\n",result);
    for (int r=1; r<= n; r++) {
        printf("%d\n",r);
        if (r==1 && result[0]=='1') {
            printf("ok\n");
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
                    printf("ok\n");
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
    int i;
    for (i = 0; i < n; i++)
        temp[i] = 0;

    char result[n];
    Permutation(0, n, arr, temp, result);
    return 0;
}
