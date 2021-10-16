#include <bits/stdc++.h>
using namespace std;

vector<int> H;

int parent(int i)
{
return (i - 1) / 2;
}

int leftChild(int i)
{
return ((2 * i) + 1);
}

int rightChild(int i)
{
return ((2 * i) + 2);
}

void shiftUp(int i)
{
    if (i == 0)
    {
        return;
    }
    int pi = parent(i);
    if (H[pi] > H[i])
    {
        cout << H[pi] << endl;
        swap(H[parent(i)], H[i]);
        i = parent(i);
        shiftUp(i);
    }
}

void shiftDown(int i)
{
    int mini = H[i];
    int maxIndex = i;

    // Left Child
    int l = leftChild(i);
    // Right Child
    int r = rightChild(i);
    if (l < H.size() && H[l] < mini)
    {
        mini = H[l];
        maxIndex = l;
    }
    if (r < H.size() && H[r] < mini)
    {
        mini = H[r];
        maxIndex = r;
    }

    if (mini != H[i])
    {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

// Function to insert a new element
// in the Binary Heap
void insert(int p)
{
    H.push_back(p);
    int lastindex = H.size() - 1;
    //cout<<lastindex<<endl;
    // Shift Up to maintain heap property
    if (H.size() > 1)
        shiftUp(lastindex);
}

// Function to extract the element with
// maximum priority
int extractMax()
{
    int result = H[0];

    // Replace the value at the root
    // with the last leaf
    H[0] = H[H.size() - 1];
    H.pop_back();
    //size = size - 1;

    // Shift down the replaced element
    // to maintain the heap property
    shiftDown(0);
    return result;
}

// Function to change the priority
// of an element
void changePriority(int i, int p)
{
    int oldp = H[i];
    H[i] = p;

    if (p > oldp)
    {
        shiftUp(i);
    }
    else
    {
        shiftDown(i);
    }
}

// Function to get value of the current
// maximum element
int getMax()
{

    return H[0];
}

// Function to remove the element
// located at given index
void remove()
{
    H[0] = H[H.size() - 1];
    H.pop_back();
    //size = size - 1;

    // Shift down the replaced element
    // to maintain the heap property
    shiftDown(0);
}

// Driver Code
int main()
{

    /*		 45 
			/	 \ 
		31	 14 
		/ \ / \ 
		13 20 7 11 
		/ \ 
	12 7 
	Create a priority queue shown in 
	example in a binary max heap form. 
	Queue will be represented in the 
	form of array as: 
	45 31 14 13 20 7 11 12 7 */

    // Insert the element to the
    // priority queue
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    ////insert(7);
    //insert(11);
    insert(13);
   // insert(7);

    int i = 0;

    // Priority queue before extracting max
    cout << "Priority Queue : ";
    while (i < H.size())
    {
        cout << H[i] << " ";
        i++;
    }

    cout << "\n";

    // Node with maximum priority
    cout << "Node with maximum priority : "
         << extractMax() << "\n";

    // Priority queue after extracting max
    cout << "Priority queue after "
         << "extracting maximum : ";
    int j = 0;
    while (j <= H.size())
    {
        cout << H[j] << " ";
        j++;
    }

    cout << "\n";

   
    remove();
    cout << "Priority queue after "
         << "removing the element : ";
    int l = 0;
    while (l <= H.size())
    {
        cout << H[l] << " ";
        l++;
    }
    return 0;
}
