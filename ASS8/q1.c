#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct activity{
char sl[10];
int s;
int f;
};

void b_sort(struct activity a[],int n){

for(int i=0;i<n-1;i++){
for(int j=i;j<n;j++){
if(a[i].f>a[j].f){
struct activity temp=a[i];
a[i]=a[j];
a[j]=temp;

}}}

}

void ASA(struct activity a[],int n){
char arr[n][10];
b_sort(a,n);
int count=1,j=1;
int curr_f=a[0].f;
strcpy(arr[0],a[0].sl);
for(int i=1;i<n;i++){
if(a[i].s>=curr_f){
strcpy(arr[j],a[i].sl);
j++;
count++;
curr_f=a[i].f;
}

}
printf("Total max no of events that can be attended is : %d\n",count);
printf("Schedule : ");
for(int i=0;i<count;i++){
printf("%s ",arr[i]);
}
printf("\n");
}


int main(){
int n;
printf("Enter the no of activities : ");
scanf("%d" ,&n);
struct activity *a = (struct activity* )malloc(n*sizeof(struct activity));


printf("Enter the activity name, start time and finish time\n");
for(int i=0;i<n;i++){
scanf("%s %d %d",a[i].sl,&a[i].s,&a[i].f);
}
ASA(a,n);                                                                                                 



return 0;
}
