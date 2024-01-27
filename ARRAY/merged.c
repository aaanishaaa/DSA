void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
int i,j,k;
int final[m+n];
while(i<nums1Size && j<nums2Size){
    if(nums1[i]<nums2[j]){
        final[k++]=nums1[i++];
    }
    else{
          final[k++]=nums2[i++];
    }
}
while(i<nums1Size){
    final[k++]=nums1[i++];
}
while(i<nums2Size){
    final[k++]=nums2[j++];
}
}
void main(){
    int nums1=[100]
    int num2=[100];
    int n,m,i,j;
    for(i=0;i<n;i++){
        scanf("%d",&nums1[i]);
    }
    for(i=0;i<m;i++){
        scanf("%d",&nums2[j]);
    }
}
}