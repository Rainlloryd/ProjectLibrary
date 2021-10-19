#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void docfile(int *&a, int &n);
void xuatmang(int *a, int n);
void baitap7(int *a, int n);
int main ()
{
    FILE *f;
    int *a,n;
    docfile(a,n);
    xuatmang(a,n);
    baitap7(a,n);
    delete []a;
}
void docfile(int *&a, int &n)
{
    FILE *f;
    if((f=fopen("E:\\Bai tap DHSG\\du lieu dau vao\\7i.txt","r"))==NULL)
    {
        printf("Khong the mo file");
        exit(0);
    }
    fscanf(f,"%d",&n);
    if(n<0)
    {
        printf("nhap n khong dung");
        exit(0);
    }
    a=new int[n];
    for(int i=0;i<n;i++)
    fscanf(f,"%d",&*(a+i));
    fclose(f);
}
void xuatmang(int *a, int n)
{
    for(int i=0;i<n;i++)
    {
    printf("%d ",*(a+i));
    printf("\n");
    }
}
void baitap7(int *a, int n)
{
    FILE *f;
    int smax=a[0];
    int j,d,c,s1,s2;
    do
    { 
        for(int i=0;i<n;i++)
        {
            s1=a[i];    
            for(int j=i+1;j<n;j++)
            {
            s2=s1+a[j];
            if(s2 > s1 || s2 < s1) {s1=s2;}
            if(smax<s1) 
            {
                smax=s1;
                d=i;
                c=j;
            }
            }
        }
    } while (j<n && s2>s1);
    d++;
    c++;
    // ghi file
        if((f=fopen("E:\\Bai tap DHSG\\du lieu dau vao\\7o.txt","w"))==NULL)
    {
        printf("Khong the mo file");
        exit(0);
    }
    fprintf(f,"%d %d %d",smax,d,c);
    fclose(f);
}