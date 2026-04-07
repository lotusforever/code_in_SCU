#include <stdio.h>
void swap(int* a,int* b){
    int temp;
    temp= *a;
    *a =*b;
    *b = temp;
}
int main()
{
    int x, y, z;
    printf("请输出三个数：");
    scanf("%d %d %d", &x, &y, &z);
    if(x>y){
        swap(&x, &y);
    }
    if(y>z){
        swap(&y, &z);
    }
    if(x>y){
        swap(&x, &y);
    }
    printf("从小到大的排序为：%d %d %d\n", x, y, z);
    return 0;
}
