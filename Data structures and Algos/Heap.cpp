// Min Heap or Max Heap
// Parent(A) > A -> Max Heap
// Heap Construction incrementally - O(nlogn)
// To insert single element - O(log n)

// A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled & all nodes are as far left as possible.

// A full binary tree is a tree in which every node other than the leaves has two children.
// Reduce memory costs by using arrays instead of nodes

class BinaryMaxHeap
{
	private:
		int *data;
		int heapSize;
		int arraySize;

		int getLeftChild(int i)
		{
			return data[2*i+1];
		}

		int getRightChild(int i)
		{
			return data[2*i+2];
		}

		int getParent(int i)
		{
			return data[(i-1)/2];
		}

	public: 
		BinaryMaxHeap(int size)
		{	
			data = new int[size];
			heapSize = 0;
			arraySize = size;
		}

		boolean isEmpty()
		{
			return (heapSize == 0);
		}

		int getMaximum()
		{
			if (heapSize > 0) return data[0];
			return NULL;
		}

		void siftUp(int currentNode)
		{
			if (getParent(currentNode) < data[currentNode])
			{	int parentIndex = (currentNode-1)/2;
				swap(data[currentNode], data[parentIndex]);
				siftUp(parentIndex);
			}

		}
		void insert(int n)
		{
			if (heapSize==arraySize)
				return NULL;	// Throw error when Heap is full
			
			else {
				heapSize++;
				data[heapSize-1] = n; // Add element to the end
				siftUp(heapSize-1);
			}
			

		}
}