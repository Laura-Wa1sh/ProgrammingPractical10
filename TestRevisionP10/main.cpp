//
//  main.cpp
//  TestRevisionP10
//
//  Created by Laura Walsh on 05/05/2019.
//  Copyright © 2019 Laura Walsh. All rights reserved.
//

#include <iostream>
#include <unistd.h>
#include <ctime>
using namespace std;

bool isSorted (int* a, int N){
    bool sort = false;
    for(int i =0; i< N-1; i++){
        if(a[i] <a[i+1])
            sort = true;
        else sort = false;
    }
    return sort;
}

void insertionSort (int *a, int N){
    for(int i =1; i<N; i++){
      // the item to be inserted in the sorted array b
        //i is one after the last item in the sorted array b
        int item = a[i];
        //search for insertion position p in n b from beginning
        int p = 0;
        while(p<i && a[p] <=item) p++;
        //move everything from position p up one place
        //starting at end i, not from p!!
        for(int j=i-1; j>=p; j--){
            a[j+1] = a[j];
            usleep(100);
        }
        //insert otem at position p
        a[p] = item;
    }
}

void quickSort (int *a, int first, int last){
    //partionioning
    int i = first;
    int j = last;
    int pivot = a[(first+last)/2];
    while(i<=j){
        while(a[i]<pivot) i++;
        while(a[j]>pivot) j--;
        if(i<=j){
            //swap
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++; j--;
        }
    }
    if(first<i-1) quickSort(a,first,i-1);
    if(i<last) quickSort(a,i,last);
}


int main(){
    int N;
    cout << "Please enter a value for N: " << endl;
    cin>> N;
    int a[N];
    for(int i = 0; i < N; i++) a[i] = 3 * i + 1;
    int b[N];
    for(int i = 0; i < N; i++) b[i] = rand() % 1000;
    
    bool tf = isSorted(a,N);
    bool tf2 = isSorted(b,N);
    
    cout << "Array a sorted = " << tf << endl;
    cout << "Array b sorted = " << tf2 << endl;
    
    return 0;
}
