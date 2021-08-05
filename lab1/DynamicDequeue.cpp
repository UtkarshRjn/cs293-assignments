#include<iostream>
#include"DynamicDequeue.h"
using namespace std;

// maximum n-1 can be kept
DynamicDequeue::DynamicDequeue(){
	/*
	This function is initializing our DynamicDequeue
	0 1 2 3 4 5 6 .....
	f
	r
	*/
	f = 0;
	r = 0;
	N = INIT_SIZE;
	double init_arr[N];
	A = init_arr;
}

bool DynamicDequeue::isEmpty(){
	/*
	0 1 2 3 4 5 6 .....
		f
		r
	when f = r it signifies that the dequeue is empty
	*/
	return (f==r);
}

bool DynamicDequeue::isFull(){

	/*
	0 1 2 3 4 5 6 ..... N-1
	f 					 r   ---> standard full case here %N has
								 been used to make sure the array 
								 is filled in a dunamic fashion.
	when f = r it signifies that the dequeue is empty
	*/
	return ( f == (r+1)%N );
}

void DynamicDequeue::grow(){
	unsigned int old_N = N;
	N = nextSizeLinear();
	// N = nextSizeExponential();
	double* new_arr = new double[N];
	
	if(f > r){
		/*
		0 1 2 3 4 5 6 ..... N-1
		* r 	f * *        *
		For this case the first r elements are copied in the new array from forward
		and the last N-f elements are copied in the backward fashion restoring the elements 
		with new size
		*/
		for(unsigned int i=0;i<r;i++){
			new_arr[i] = A[i];
		}
		for(unsigned int i=0;i<old_N-f;i++){
			new_arr[f-old_N+N+i] = A[f+i];
		}
	}
	else{
		/*
		0 1 2 3 4 5 6 ..... N-1
		  f * *	r  
		In this regular case the elements are simply copied from f to r in the new array
		*/
		for(unsigned int i=f;i<r;i++){
			new_arr[i] = A[i];
		}
	}
	A = new_arr; // The pointer of previous array A is reinitialized to the pointer of new array of 
				// new size
}

unsigned int DynamicDequeue::size(){
	return (N-f+r)%N; // Standard size formula from the Naveen garg's slide
}

void DynamicDequeue::insertFront(double x){

	if(isFull()) grow(); // If is full the dequqe is grown
	
	// This part is same whether the deque is full or not
	f = (N+f-1)%N;
	A[f] = x;

}

void DynamicDequeue::insertRear(double x){

	if(isFull()) grow();
	
	r = (r+1)%N;
	A[r] = x;
}

bool DynamicDequeue::removeFront(double *x){
	if(isEmpty()) return false;
	else{
		*x = A[f]; // The value of pointer changed to the front array element
		A[f] = '\0'; // front element initialized to null
		f = (f+1)%N; // updated f
		return true;
	}
}

bool DynamicDequeue::removeRear(double *x){
	if(isEmpty()) return false;
	else{
		*x = A[r];
		A[r] = '\0';
		r = (N+r-1)%N;
		return true;
	}
}

bool DynamicDequeue::front(double *x){
	if(isEmpty()) return false;
	else{
		*x = A[f];
		return true;
	}
}

bool DynamicDequeue::rear(double *x){
	if(isEmpty()) return false;
	else{
		*x = A[r]; // The value of pointer changed to the front array element
		return true;
	}

}