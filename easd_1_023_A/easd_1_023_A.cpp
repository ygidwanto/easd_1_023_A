// 1. karena algoritma memiliki efiesiensi dalam menyelesaikan suatu maslah dalam bentuk program
// 2. structur data: - Statistic example array
//                   - Dynamic example linked list
// 3. faktor yang mempengaruhi efisiensi program: - Speed of the machine
//											      - Compiler
//											      - Operating System
//											      - Programing languange
//											      - Size of the input
// 4. Merge sort algoritma, karena memiliki langkah yang efisien dalam melakukan sortir banyak data 
// 5. yang termasuk Quadratic : bubble sort
//                  Loglinier : shell sort
// 6.

#include <iostream>
using namespace std;

//array of integers to hold values
int yogi[20];
int cmp_count = 0; // number of comparasion
int mov_count = 0; // number of data movements
int n;
void input() {
	while (true)
	{
		cout << "Memasukan panjang element array: 20 ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMaksimum panjang array adalah 20" << endl;
	}

	cout << "\n===================" << endl;
	cout << "\nEnter Array Element" << endl;
	cout << "\n===================" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> yogi[i];
	}
}
// swaps the element at index x with the element at index y
void swap(int x, int y)
{
	int temp;

	temp = yogi[x];
	yogi[x] = yogi[y];
	yogi[y] = temp;
}

void marge_sort(int low, int high)
{
	int pivot, i, j;
	if (low> high)
		return;                                               // Langkah 1

	//Partition the list into two part:
	//one containing elements less that or equal to pivot
	//Pither conntaining elements greather than pivot 

	pivot = yogi[low];                                         // Langkah 2

	i = low;                                              // Langkah 3
	j= low+1;                                                 // Langkah 4


	while (i <= j)
	{
		//search for an element greater than pivot
		while ((yogi[j] <= pivot) && (i <= high))             // Langkah 5
		{
			i++;                                             // Langkah 6
			cmp_count++;
		}
		cmp_count++;
		//search for an element less than or equal to pivot
		while ((yogi[j] > pivot) && (j >= low))               // Langkah 7
		{
			j--;                                             // Langkah 8
			cmp_count++;
		}
		cmp_count++;

		// Langkah 9
		if (i < j) // if the greater element is ont the left of the element
		{
			//Swap the element at index i whit the element in at index j
			swap(i, j);
			mov_count++;
		}
	}
	//j now containt the index of the last element in the sorted list
	if (low < j);											// Langkah 11
	{
		//move the pivot to its correct position in the list 
		swap(low, j);
		mov_count++;
	}


	//sort the list list on the left of pivot using quck sort
	marge_sort(low, j - 1);                                    // Langkah 12
	//Short the list on the right of pivot using quick sort
	marge_sort(j + 1, high);                                   // Langkah 13

}


void display() {
	cout << "\n=======================" << endl;
	cout << "Sorted Array" << endl;
	cout << "===================" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << yogi[i] << " ";
	}

	cout << "\n\nNumber of comparations: " << cmp_count << endl;
	cout << "Number of data movements: " << mov_count << endl;
}


int main()
{

	input();
	//Sort the array using quick sort
	marge_sort(0, n - 1);
	display();
	system("pause");

	return 0;
}
