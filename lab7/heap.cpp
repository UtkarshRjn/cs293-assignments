#include<iostream>
#include<fstream>
#include"heap.h"
using namespace std;

void swap(ll* a, ll* b) 
{ 
    ll temp = *a; 
    *a = *b; 
    *b = temp; 
}


Heap::Heap(){
	N = 0;
	capacity = 1LL << 22;
	arr = new ll[capacity];
}

void Heap::insert(ll key, ll &n_swap){

	N++;
	ll i = N-1;
	arr[i] = key;
	while(i != 0 && arr[parent(i)] > arr[i]){
		swap(&arr[parent(i)], &arr[i]);
		n_swap++;
		i = parent(i);
	}

}

void Heap::heapify(ll i, ll &n_swap){
	ll l = left(i);
	ll r = right(i);
	ll smallest = i;
	if(l < N && arr[l] < arr[i]){
		smallest = l;
	}
	if(r < N && arr[r] < arr[smallest]){
		smallest = r;
	}
	if(smallest != i){
		swap(&arr[i], &arr[smallest]);
		n_swap++;
		heapify(smallest,n_swap);
	}
}

void Heap::deleteMin(ll &n_swap){
	swap(&arr[0],&arr[N-1]);
	n_swap++;
	N--;
	heapify(0,n_swap);
}

int main(){
	
	srand(time(0));
	Heap my_heap;
	
	ofstream swapFile("swap.csv");
	ofstream timeFile("time.csv");
	double avg_insert[4][2],avg_delete[4][2]; // avg_insert[i][0] contains average swaps; avg_insert[i][1] contains average time for insert operation;	
	for(ll N=1000,j=0;N<=1e6;N*=10,j++){  
		ll x = 0;
		for(ll i=0;i<N;i++){
			my_heap.insert(rand(),x);
		}

		ll n_insert = 0, n_deleteMin = 0;
		ll n_swap_insert = 0, n_swap_deleteMin = 0;
		double time_insert = 0, time_deleteMin = 0;
		for(ll i=0;i<N/5;i++){
			ll t = rand();
			if(t%2 == 0){
				clock_t tStart = clock();
				my_heap.deleteMin(n_swap_deleteMin);
				time_deleteMin += (double)(clock() - tStart)/CLOCKS_PER_SEC;
				n_deleteMin++;
			}else{
				clock_t tStart = clock();	
				my_heap.insert(t, n_swap_insert);
				time_insert += (double)(clock() - tStart)/CLOCKS_PER_SEC;
				n_insert++;
			}
		}
		avg_insert[j][0] = (double)n_swap_insert/n_insert;
		avg_delete[j][0] = (double)n_swap_deleteMin/n_deleteMin;
		swapFile << avg_insert[j][0] << "," << avg_delete[j][0] << endl;
		
		avg_insert[j][1] = time_insert/n_insert;
		avg_delete[j][1] = time_deleteMin/n_deleteMin;
		timeFile << avg_insert[j][1] << "," << avg_delete[j][1] << endl;
	}

}