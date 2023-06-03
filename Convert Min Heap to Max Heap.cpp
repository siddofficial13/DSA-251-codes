/*
    Time Complexity : O(N)
    Space complexity : O(log(N))

    where N is the size of the input array/heap
*/

void heapify(long *arr, int n, int currentIndex)
{
    int leftChildIndex = 2 * currentIndex + 1;
    int rightChildIndex = 2 * currentIndex + 2;
    int largestIndex = currentIndex;

    // Find the largest element among current node and its children.
    if (leftChildIndex < n && arr[leftChildIndex] > arr[currentIndex])
    {
        largestIndex = leftChildIndex;
    }
    if (rightChildIndex < n && arr[rightChildIndex] > arr[largestIndex])
    {
        largestIndex = rightChildIndex;
    }

    // In case the current node is not the largest, swap the current and smallest node.
    // Make a recursive call to the child which was the smallest after swapping.
    if (largestIndex != currentIndex)
    {
        // Swapping the value at current index and the largestIndex
        long temp = arr[currentIndex];
        arr[currentIndex] = arr[largestIndex];
        arr[largestIndex] = temp;

        // Making a recusrive call to the largest index.
        heapify(arr, n, largestIndex);
    }
}

// Converting the min heap to max heap
void minHeapToMaxHeap(long *arr, int n)
{
    // Heapifying all nodes from the bottom right
    for (int i = n / 2; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}
