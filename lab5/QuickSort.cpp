#include<iostream>
#include<strings.h>
#include <fstream>
using namespace std;

#define MAX_SIZE (int)5000
typedef long long ll;

struct Results{
	ll num_comparisions;
	ll num_swaps;
};

void swap(double* a, double* b) 
{ 
    double temp = *a; 
    *a = *b; 
    *b = temp; 
}

int partition (double arr[], int p, int r, ll &num_comparisions, ll &num_swaps) 
{ 
    double pivot = arr[p];
    int i = p-1;

    for (int j = p; j <= r - 1; j++){ 
 
        if (arr[j] < pivot) 
        { 
            i++;
            swap(&arr[i], &arr[j]);
            num_swaps++;
            num_comparisions++; 
        }
        num_comparisions++;
    } 
    swap(&arr[i + 1], &arr[r]);
    num_swaps++; 
    return (i + 1);
}

int randomized_partition(double arr[], int p, int r, ll &num_comparisions, ll &num_swaps){

	srand(time(0));	
	int i = (rand()%(r-p)) + p;
	swap(&arr[r],&arr[i]);
	num_swaps++;
	return partition(arr, p, r,num_comparisions,num_swaps);
}

Results quickSort(double arr[], int p, int r, ll &num_comparisions,ll &num_swaps) 
{ 
    if(p < r){ 
        int q = partition(arr, p, r,num_comparisions,num_swaps); 
 
        quickSort(arr, p, q-1,num_comparisions,num_swaps); 
        quickSort(arr, q+1, r,num_comparisions,num_swaps); 
    }
	return {num_comparisions,num_swaps};
}

Results randomized_quickSort(double arr[], int p, int r, ll &num_comparisions, ll &num_swaps){

	if(p < r){
		int q = randomized_partition(arr, p, r,num_comparisions,num_swaps);
		
		randomized_quickSort(arr, p, q-1,num_comparisions,num_swaps);
		randomized_quickSort(arr, q+1, r,num_comparisions,num_swaps);
	}
	return {num_comparisions,num_swaps};
}

Results bubbleSort(double arr[], int n){

	long long num_comparisions = 0,num_swaps = 0;
	int n_swap = -1;
	while(n_swap != 0){
		n_swap = 0;
		for(int i=0;i < n-1;i++){
			if(arr[i] > arr[i+1]){
				swap(&arr[i],&arr[i+1]);
				n_swap++;
				num_swaps++;
				num_comparisions++;
			}
		}
	}
	return {num_comparisions,num_swaps};
}

void printArray(int arr[], int size){ 
    
    for (int i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

void randomize(double arr[], int size, double p){

	int i = (size*(1-p))/2;
	while(i--){
		swap(arr[rand()%size], arr[rand()%size]);
	}
}

void initialize(double random_array[],double almost_sorted_array[],double rev_almost_sorted_array[], int N){
	
	for(int i=0;i<N;i++){
		random_array[i] = rand()%N;
		almost_sorted_array[i] = i;
		rev_almost_sorted_array[N-i-1] = i;
	}
	randomize(almost_sorted_array,N,0.9);
	randomize(rev_almost_sorted_array,N,0.9);
}

int main(){

	// -------- runtime --------


	srand(time(0));

	ofstream runtime_file1("runtime_random.txt");
	ofstream runtime_file2("runtime_almost_sorted.txt");
	ofstream runtime_file3("runtime_rev_almost_sorted.txt");

	ofstream comparisions_file1("comparisions_random.txt");
	ofstream comparisions_file2("comparisions_almost_sorted.txt");
	ofstream comparisions_file3("comparisions_rev_almost_sorted.txt");

	ofstream swaps_file1("swaps_random.txt");
	ofstream swaps_file2("swaps_almost_sorted.txt");
	ofstream swaps_file3("swaps_rev_almost_sorted.txt");

	double runtime_QSP1[100][3]; // column 1 for random/ column 2 for almost_sorted/ column 3 for rev_almost_sorted
	double runtime_QSRP[100][3];
	double runtime_BuSo[100][3];

	ll comparisions_QSP1[100][3];
	ll comparisions_QSRP[100][3];
	ll comparisions_BuSo[100][3];

	ll swaps_QSP1[100][3];
	ll swaps_QSRP[100][3];
	ll swaps_BuSo[100][3];

	for(int N=0,j=0;N<MAX_SIZE;N+=MAX_SIZE/100,j++){
		double random_array[N];
		double almost_sorted_array[N];
		double rev_almost_sorted_array[N];
		Results r;
 		//--------------------QSP1-----------------------// 

		initialize(random_array,almost_sorted_array,rev_almost_sorted_array,N);
		
		clock_t tStart = clock();
		r = {0,0};
		r = quickSort(random_array, 0, N-1,r.num_comparisions,r.num_swaps);
		comparisions_QSP1[j][0] = r.num_comparisions;
		swaps_QSP1[j][0] = r.num_swaps;
		runtime_QSP1[j][0] = (double)(clock() - tStart)/CLOCKS_PER_SEC;

		tStart = clock();
		r = {0,0};
		r = quickSort(almost_sorted_array, 0, N-1,r.num_comparisions,r.num_swaps);
		comparisions_QSP1[j][1] = r.num_comparisions;
		swaps_QSP1[j][1] = r.num_swaps;
		runtime_QSP1[j][1] = (double)(clock() - tStart)/CLOCKS_PER_SEC;

		tStart = clock();
		r = {0,0};
		r = quickSort(rev_almost_sorted_array, 0, N-1,r.num_comparisions,r.num_swaps);	
		comparisions_QSP1[j][2] = r.num_comparisions;
		swaps_QSP1[j][2] = r.num_swaps;		
		runtime_QSP1[j][2] = (double)(clock() - tStart)/CLOCKS_PER_SEC;
	
 		//--------------------QSRP-----------------------// 

		initialize(random_array,almost_sorted_array,rev_almost_sorted_array,N);
		
		tStart = clock();
		r = {0,0};
		r = randomized_quickSort(random_array, 0, N-1,r.num_comparisions,r.num_swaps);
		comparisions_QSRP[j][0] = r.num_comparisions;
		swaps_QSRP[j][0] = r.num_swaps;		
		runtime_QSRP[j][0] = (double)(clock() - tStart)/CLOCKS_PER_SEC;

		tStart = clock();
		r = {0,0};
		randomized_quickSort(almost_sorted_array, 0, N-1,r.num_comparisions,r.num_swaps);
		comparisions_QSRP[j][1] = r.num_comparisions;
		swaps_QSRP[j][1] = r.num_swaps;			
		runtime_QSRP[j][1] = (double)(clock() - tStart)/CLOCKS_PER_SEC;

		tStart = clock();
		r = {0,0};
		randomized_quickSort(rev_almost_sorted_array, 0, N-1,r.num_comparisions,r.num_swaps);
		comparisions_QSRP[j][2] = r.num_comparisions;
		swaps_QSRP[j][2] = r.num_swaps;				
		runtime_QSRP[j][2] = (double)(clock() - tStart)/CLOCKS_PER_SEC;

 		//--------------------BuSo-----------------------// 

		initialize(random_array,almost_sorted_array,rev_almost_sorted_array,N);
		
		tStart = clock();
		r = {0,0};
		r = bubbleSort(random_array,N);
		comparisions_BuSo[j][0] = r.num_comparisions;
		swaps_BuSo[j][0] = r.num_swaps;			
		runtime_BuSo[j][0] = (double)(clock() - tStart)/CLOCKS_PER_SEC;

		tStart = clock();
		r = {0,0};
		r = bubbleSort(almost_sorted_array, N);
		comparisions_BuSo[j][1] = r.num_comparisions;
		swaps_BuSo[j][1] = r.num_swaps;		
		runtime_BuSo[j][1] = (double)(clock() - tStart)/CLOCKS_PER_SEC;

		tStart = clock();
		r = {0,0};
		r = bubbleSort(rev_almost_sorted_array, N);	
		comparisions_BuSo[j][2] = r.num_comparisions;
		swaps_BuSo[j][2] = r.num_swaps;		
		runtime_BuSo[j][2] = (double)(clock() - tStart)/CLOCKS_PER_SEC;

	}

	for(int i=0;i<100;i++){
		
		runtime_file1 << i*MAX_SIZE/100 << " " << runtime_QSP1[i][0] << " " << runtime_QSRP[i][0] << " " << runtime_BuSo[i][0] << endl;
		runtime_file2 << i*MAX_SIZE/100 << " " << runtime_QSP1[i][1] << " " << runtime_QSRP[i][1] << " " << runtime_BuSo[i][1] << endl;
		runtime_file3 << i*MAX_SIZE/100 << " " << runtime_QSP1[i][2] << " " << runtime_QSRP[i][2] << " " << runtime_BuSo[i][2] << endl;

		comparisions_file1 << i*MAX_SIZE/100 << " " << comparisions_QSP1[i][0] << " " << comparisions_QSRP[i][0] << " " << comparisions_BuSo[i][0] << endl;
		comparisions_file2 << i*MAX_SIZE/100 << " " << comparisions_QSP1[i][1] << " " << comparisions_QSRP[i][1] << " " << comparisions_BuSo[i][1] << endl;
		comparisions_file3 << i*MAX_SIZE/100 << " " << comparisions_QSP1[i][2] << " " << comparisions_QSRP[i][2] << " " << comparisions_BuSo[i][2] << endl;

		swaps_file1 << i*MAX_SIZE/100 << " " << swaps_QSP1[i][0] << " " << swaps_QSRP[i][0] << " " << swaps_BuSo[i][0] << endl;
		swaps_file2 << i*MAX_SIZE/100 << " " << swaps_QSP1[i][1] << " " << swaps_QSRP[i][1] << " " << swaps_BuSo[i][1] << endl;
		swaps_file3 << i*MAX_SIZE/100 << " " << swaps_QSP1[i][2] << " " << swaps_QSRP[i][2] << " " << swaps_BuSo[i][2] << endl;

	}



}