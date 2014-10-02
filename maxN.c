/*=============================================================
*	
*	I don't konw if you guys call it heap sort, but I do.
*	So here it is...
*
=============================================================*/
#include <stdio.h>

//make the heap s a minimum heap 
void heapArrange(int arr[], int s, int n){
	if(arr == NULL || s < 0 || n < 0){
		throw "input error in heapArrange!";
	}
	int tmp = arr[s];
	for(int j = s*2+1; j <= n; j = j*2+1){
		if(j+1 <= n && arr[j] > arr[j+1]){
			j++;
		}
		if(arr[j] > tmp){
			break;
		}
		arr[s] = arr[j];
		s = j;
	}
	arr[s] = tmp;
}

// maintain a minimum heap
void heapAdjust(int arr[], int length){
	if(arr == NULL || length <= 0){
		throw "input error in heapAdjust!";
	}
	for(int i = length/2-1; i >= 0; i--){
		heapArrange(arr, i, length-1);
	}
}
