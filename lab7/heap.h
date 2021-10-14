#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

class Heap{

	private:
		ll capacity;
		ll N;
		ll *arr;

	public:

		Heap();

		ll parent(ll i) {return (i-1)/2;}
		ll left(ll i) {return 2*i+1;}
		ll right(ll i) {return 2*i+2;}

		void insert(ll key, ll &n_swap);
		ll min(){ return arr[0];}
		void heapify(ll i, ll &n_swap);
		void deleteMin(ll &n_swap);

};