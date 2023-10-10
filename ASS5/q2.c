#include<stdio.h>
int min(int a, int mini){
if(a<mini) return a;
return mini;
}

int max(int ans, int diff){
if(ans>diff) return ans;
return diff;
}
int LD(int arr[],int n){
int mini=arr[0],diff=0;
int ans=0;
for(int i=1;i<n;i++){
int a=arr[i];
mini=min(a,mini);
diff=a-mini;
ans=max(ans,diff);
}
if(ans<=0) return -1;
return ans;
}

int main(){
printf("Enter the no of elements : ");
int n;
scanf("%d",&n);
int arr[n];
printf("Enter the elements : ");
for(int i=0;i<n;i++){
scanf("%d",&arr[i]);
}
printf("%d\n",LD(arr,n));
return 0;
}
