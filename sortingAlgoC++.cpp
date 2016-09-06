#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<assert.h>
using namespace std;

/*Display Function For an Array*/
void disp(int a[],int len){

    for(int i=0;i<len;i++){
        cout<<a[i]<<" ";
    }
}

/*Bubble Sort*/
void buble_sort(int a[],int len){

    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
}

/*Selection Sort*/
void selection_sort(int a[],int len){

    for(int i=0;i<len-1;i++){
        int min=i;
        for(int j=i+1;j<len;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        swap(a[i],a[min]);
    }
}

/*Insertion Sort*/
void insertion_sort(int a[],int len){

    for(int i=0;i<len;i++){
        int j=i,temp=a[i];
        while(temp<a[j-1] && j>0){
            a[j]=a[j-1];
            j--;
        }
        a[j]=temp;
    }
}

/*Merging two sorted Array*/
void merge_array(int a[],int start,int mid,int end){
    int temp[end-start+1];int k=start;
    int i=start;int j=mid+1;
    while(i<=mid && j<=end){
        if(a[i]<=a[j]){
            temp[k++]=a[i++];
        }
        else
            temp[k++]=a[j++];
        }
        while(i<mid+1){
            temp[k++]=a[i++];
        }
        while(j<end+1){
            temp[k++]=a[j++];
        }
    for(int p=start;p<=end;p++){
        a[p]=temp[p];
    }
}

/*Merge Sort*/
void merge_sort(int a[],int start,int end){
    if(start<end){
        int mid=(start+end)/2;
        merge_sort(a,start,mid);
        merge_sort(a,mid+1,end);
        merge_array(a,start,mid,end);
    }
}

/*Partition of Array*/
int partition_array(int a[],int start,int end){
    int i=start+1;
    int pivotElement = a[start];
    for(int j=start+1;j<=end;j++){
        if(pivotElement>a[j]){
            swap(a[i],a[j]);
        }
        i++;
    }
    swap(a[start],a[i-1]);
    return i-1;
}

/*Quick Sort*/
void quick_sort(int a[],int start,int end){
    if(start < end){
    int pivotLoc = partition_array(a,start,end);
    quick_sort(a,start,pivotLoc-1);
    quick_sort(a,pivotLoc+1,end);
    }
}
int main(){
    int arr[]={11,2,3,44,5,66,77,112,33,32};
    int len = sizeof(arr)/sizeof(arr[0]);
    /*buble_sort(arr,len);*/
    /*selection_sort(arr,len);*/
    /*insertion_sort(arr,len);*/
    /*merge_array(arr,0,4,10);*/
    merge_sort(arr,0,len-1);
    //quick_sort(arr,0,len-1);
    disp(arr,len);
    return 0;
}
