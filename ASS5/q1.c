#include<stdio.h>
#include<time.h>

int LSS(int arr[],int n){
int ans=arr[0];
int temp=0;

for(int i=0;i<n;i++){
temp+=arr[i];
if(temp>ans){
ans=temp;
}
if(temp<0){
temp=0;
}
}
return ans;
}

int main(){
int n;
printf("Enter the array size : ");
scanf("%d",&n);
int arr[n];
printf("Enter the elements : ");
for(int i=0;i<n;i++){
scanf("%d",&arr[i]);
}
printf("%d\n",LSS(arr,n));
return 0;
}
