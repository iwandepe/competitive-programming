// A C++ program to demonstrate common Binary Heap Operations 
#include<iostream> 
#include<climits> 
using namespace std; 

typedef struct {
	int h,x,y;
}cube;

// Prototype of a utility function to swap two integers 
void swap(cube *x, cube *y); 

// A class for Min Heap 
class MinHeap 
{ 
	cube *harr; // pointer to array of elements in heap 
	int capacity; // maximum possible size of min heap 
public: 
	int heap_size; // Current number of elements in min heap 
	// Constructor 
	MinHeap(int capacity); 

	// to heapify a subtree with the root at given index 
	void MinHeapify(int ); 

	int parent(int i) { return (i-1)/2; } 

	// to get index of left child of node at index i 
	int left(int i) { return (2*i + 1); } 

	// to get index of right child of node at index i 
	int right(int i) { return (2*i + 2); } 

	// to extract the root which is the minimum element 
	cube extractMin(); 
	
	// Decreases key value of key at index i to new_val 
    void decreaseKey(int x, int y, int new_val); 
  
    // Returns the minimum key (key at root) from min heap 
    cube getMin() { return harr[0]; } 
  
    // Deletes a key stored at index i 
    void deleteKey(int x, int y); 

	// Inserts a new key 'k' 
	void insertKey(int k, int x, int y); 
}; 

// Constructor: Builds a heap from a given array a[] of given size 
MinHeap::MinHeap(int cap) 
{ 
	heap_size = 0; 
	capacity = cap; 
	harr = new cube[cap]; 
} 

// Decreases value of key at index 'i' to new_val.  It is assumed that 
// new_val is smaller than harr[i]. 
void MinHeap::decreaseKey(int x, int y, int new_val) 
{ 
	int i;
	for (i=0; i<heap_size; i++){
		if (harr[i].x == x && harr[i].y == y)
			harr[i].h = new_val;
	}
    while (i != 0 && harr[parent(i)].h > harr[i].h) 
    { 
       swap(&harr[i], &harr[parent(i)]); 
       i = parent(i); 
    } 
} 

// This function deletes key at index i. It first reduced value to minus 
// infinite, then calls extractMin() 
void MinHeap::deleteKey(int x, int y) 
{ 
    decreaseKey(x, y, INT_MIN); 
    extractMin(); 
} 

// Inserts a new key 'k' 
void MinHeap::insertKey(int k, int x, int y) 
{ 
	if (heap_size == capacity) 
	{ 
		cout << "\nOverflow: Could not insertKey\n"; 
		return; 
	} 

	// First insert the new key at the end 
	heap_size++; 
	int i = heap_size - 1; 
	harr[i].h = k; 
	harr[i].x = x;
	harr[i].y = y;

	// Fix the min heap property if it is violated 
	while (i != 0 && harr[parent(i)].h > harr[i].h) 
	{ 
		swap(&harr[i], &harr[parent(i)]); 
		i = parent(i); 
	} 
} 

// Method to remove minimum element (or root) from min heap 
cube MinHeap::extractMin() 
{ 
	if (heap_size == 1) 
	{ 
		heap_size--; 
		return harr[0]; 
	} 

	// Store the minimum value, and remove it from heap 
	cube root = harr[0]; 
	harr[0] = harr[heap_size-1]; 
	heap_size--; 
	MinHeapify(0); 

	return root; 
} 

// A recursive method to heapify a subtree with the root at given index 
// This method assumes that the subtrees are already heapified 
void MinHeap::MinHeapify(int i) 
{ 
	int l = left(i); 
	int r = right(i); 
	int smallest = i; 
	if (l < heap_size && harr[l].h < harr[i].h) 
		smallest = l; 
	if (r < heap_size && harr[r].h < harr[smallest].h) 
		smallest = r; 
	if (smallest != i) 
	{ 
		swap(&harr[i], &harr[smallest]); 
		MinHeapify(smallest); 
	} 
} 

// A utility function to swap two elements 
void swap(cube *x, cube *y) 
{ 
	cube temp = *x; 
	*x = *y; 
	*y = temp; 
} 

// Driver program to test above functions 
int main() 
{ 
	int t;
	cin>>t;
	while (t--)
	{
		bool visited[100][100];
		int arr[100][100];
		MinHeap heap(100*100);
		
		int n,m;
		cin>>n>>m;
		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
				cin>>arr[i][j];
				
				// pojok
				if (i==0 && j==0) continue;
				if (i==n-1 && j==0) continue;
				if (i==0 && j==m-1) continue;
				if (i==n-1 && j==m-1) continue;
				
				// boundaries
				if (i==0 || j==0 || i==n-1 || j==m-1) heap.insertKey(arr[i][j],i,j);
				visited[i][j] = false;
			}
		}
		
		int total_volume = 0;
		while (heap.heap_size>0){
			
			cube cb = heap.extractMin();
			int x = cb.x;
			int y = cb.y;
			int h = cb.h;
			
			if (visited[x][y]) continue;
			
			visited[x][y] = true;
			
			if (x+1<n-1 && !visited[x+1][y]){
				if (arr[x+1][y] < h){
					total_volume += h-arr[x+1][y];
					arr[x+1][y] = h;
				}
				heap.insertKey(arr[x+1][y],x+1,y);
			}
			
			if (x-1>0 && !visited[x-1][y]){
				if (arr[x-1][y] < h){
					total_volume += h-arr[x-1][y];
					arr[x-1][y] = h;
				}
				heap.insertKey(arr[x-1][y],x-1,y);
			}
			
			if (y+1<m-1 && !visited[x][y+1]){
				if (arr[x][y+1] < h){
					total_volume += h-arr[x][y+1];
					arr[x][y+1] = h;
				}
				heap.insertKey(arr[x][y+1],x,y+1);
			}
			
			if (y-1>0 && !visited[x][y-1]){
				if (arr[x][y-1] < h){
					total_volume += h-arr[x][y-1];
					arr[x][y-1] = h;
				}
				heap.insertKey(arr[x][y-1],x,y-1);
			}
		}
		cout << total_volume << endl;
	}
	return 0; 
} 
