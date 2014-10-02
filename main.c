/***********************************************************
 *Filename:				main.c
 *Description:			First file in this repository, find
 *						the max N numbers in a long list.
 *Author:				andyone2003 <andyone2003@gmail.com>
 *Date:					2014/10/02
 *Copyright:			Hangzhou Youwen Automation Ltd.
 **********************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include "maxN.h"

const char* filePath = "test.txt";
#define N 10

int main()
{
	int arr[N] = {0};
	std::ifstream file(filePath);
	std::string line;
	// go through the list and store the max N numbers in a heap
	while(getline(file, line)){
		int tmp = atoi(line.data());
		if(tmp > arr[0]){
			arr[0] = tmp;
			heapAdjust(arr, N);
		}
	}
	// print them
	std::cout << "The max " << N << "numbers are ：" << std::endl;
	for(int i = 0; i < N; i++){
		std::cout << arr[i] << " "; 
	}
	// sort and then print
	std::cout << std::endl;
	for(int i = N-1; i > 0; i--){
		int tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;
		heapArrange(arr, 0, i-1);
	}
	for(int i = 0; i < N; i++){
		std::cout << arr[i] << " "; 
	}
	std::cout << std::endl;
	
	return 0;
} 
