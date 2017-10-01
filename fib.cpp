#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <typeinfo>
#include <time.h>
using namespace std;

int recursivefib(int n){
	if(n==0){
		return(0);
	}
	else if(n==1){
		return(1);
	}
	else{
		return(recursivefib(n-1) + recursivefib(n-2));
	}
}
int iterativefib(int n){
	if(n==0){
		return(0);
	}
	int arr [n];
	arr[0] = 0;
	arr[1] = 1;
	for(int i = 2; i < n+1; i++){
		arr[i] = arr[i-1] + arr[i-2];
	}
	return(arr[n]);
}
int main(){
	clock_t t1,t2;
	cout << "enter a number" << endl;
	int n;
	cin >> n;
	t1 = clock();
	cout << recursivefib(n) << endl;
	t2 = clock();
	float diff ((float)t2-(float)t1);
	float seconds = diff / CLOCKS_PER_SEC;
	cout << seconds << endl;
	cout << "now times 1,000,000" << endl;
	t1 = clock();
	for(int i = 0; i < 999999; i++){
		iterativefib(n);
	}
	cout << iterativefib(n) << endl;
	t2 = clock();
	diff = ((float)t2-(float)t1);
	seconds = diff / CLOCKS_PER_SEC;
	cout << seconds << endl;
	return(0);
}