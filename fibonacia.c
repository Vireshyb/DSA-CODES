#include <stdio.h>
#include<stdlib.h>
int main() {
    FILE *fp,*fp2;
    fp=fopen("output.txt","w");
    fp2=fopen("read.txt","r");
    if(fp==NULL ||fp2==NULL )
    {
        printf("not found\n");
    }

    int n, s = 0;
    fscanf(fp2,"%d", &n);
    int prev = 0;
    int curr = 1;
     fprintf(fp,"%d\n", prev);
    for (int i = 1; i < n; i++) {
        s = prev + curr;
        fprintf(fp,"%d\n", s);
        prev = curr;
        curr = s;
    }
     fclose(fp2);
    fclose(fp);
    return 0;
}

