#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;
void docfile(int *&a, int &n);
void xuatmang(int *a, int n);
void diemyenngua_diaphuong(int *a, int n);
int main ()
{
    int *a,n;
    FILE *f;
    docfile(a,n);
    xuatmang(a,n);
    cout << "diem cuc tieu dia phuong:";
    diemyenngua_diaphuong(a,n);
    delete []a;
    fclose(f);
}
void docfile(int *&a, int &n)
{
    FILE *f;
    if((f=fopen("E:\\Bai tap DHSG\\Ky thuat lap trinh\\du lieu dau vao\\mang2chieu.txt","r"))==NULL)
    {
        printf("Can't open file");
        exit(0);
    }
    fscanf(f,"%d%d",&n,&n);
    if(n%2==0)
    {
        printf("so n nhap vao khong hop le");
        exit(1);
    }
    a=new int[n*n];
    if(a==NULL)
    {
        cout << "not enough memory";
        exit(0);
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        fscanf(f,"%d",&*(a+n*i+j));
}
void xuatmang(int *a, int n)
{
    for(int i=0;i<n;i++)
    {
        printf("\n");
        for(int j=0;j<n;j++)
        printf("%5d",*(a+n*i+j));
    }
    printf("\n");
}
void diemyenngua_diaphuong(int *a, int n)
{
    
    int min_toancuc=INT_MAX;
    int min_diaphuong=INT_MAX;
    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<n-1;j++)
        {
            if(*(a+n*i+j)<*(a+n*(i-1)+(j-1)) && *(a+n*i+j)<*(a+n*(i+1)+(j+1)) && *(a+n*i+j)<*(a+n*(i-1)+j) && *(a+n*i+j)<*(a+n*(i-1)+(j+1)) && *(a+n*i+j)<*(a+n*i+(j-1)) && *(a+n*i+j)<*(a+n*i+(j+1)) && *(a+n*i+j)<*(a+n*(i+1)+(j-1)) && *(a+n*i+j)<*(a+n*(i+1)+j))
            {
            min_diaphuong=*(a+n*i+j);
            cout << min_diaphuong << " ";
            }
            else
            {
                j++;
                if(*(a+n*i+j)<*(a+n*(i-1)+(j-1)) && *(a+n*i+j)<*(a+n*(i+1)+(j+1)) && *(a+n*i+j)<*(a+n*(i-1)+j) && *(a+n*i+j)<*(a+n*(i-1)+(j+1)) && *(a+n*i+j)<*(a+n*i+(j-1)) && *(a+n*i+j)<*(a+n*i+(j+1)) && *(a+n*i+j)<*(a+n*(i+1)+(j-1)) && *(a+n*i+j)<*(a+n*(i+1)+j))
                {
                    min_diaphuong=*(a+n*i+j);
                    cout << min_diaphuong << " "; 
                }
            }
        }
    }
        cout << endl;
        if (min_diaphuong<min_toancuc)
        {
        min_toancuc=min_diaphuong;
        cout << endl;
        cout << "diem cuc tieu toan cuc: " << min_toancuc;
        }

}