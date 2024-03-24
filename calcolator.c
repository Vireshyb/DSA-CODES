#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp,*fp2;
    fp=fopen("read.txt","r");
    fp2=fopen("output.txt","a");
    if (fp==NULL||fp2==NULL)
    {
        printf("not found\n");
    }

    int sw;
    fscanf(fp,"%d",&sw);
    printf("%d\n",sw);
    int a,b,r;
    fscanf(fp,"%d %d",&a,&b);
    printf("%d %d\n",a,b);
    switch(sw)
    {
        case 1:r=a+b;
        fprintf(fp2,"%d\n",r);
        break;
         case 2:r=a-b;
          fprintf(fp2,"%d\n",r);
        break;
         case 3:r=a*b;
          fprintf(fp2,"%d\n",r);
        break;
         case 4:r=a/b;
          fprintf(fp2,"%d\n",r);
        break;
         case 5:r=a%b;
          fprintf(fp2,"%d\n",r);
        break;

    }
    fclose(fp);
    fclose(fp2);
}
