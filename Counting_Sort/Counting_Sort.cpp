#include<iostream>
using namespace std;
void counting_sort(int input_array[], int size, int range)
{
	int *output_array=new int[size];
	int *count_array=new int[range];
		for(int i=0;i<range;i++)
		{
			count_array[i]=0;
		}
	for (int i = 0; i < size; i++)
	{
		++count_array[input_array[i]];
	}
	for (int i = 1; i < range; i++)
	{
		count_array[i] = count_array[i] + count_array[i - 1];
	}
	for (int i = 0; i < size; i++)
	{
		output_array[--count_array[input_array[i]]] = input_array[i];
	}
	for (int i = 0; i < size; i++)
	{
		input_array[i] = output_array[i];
	}
}
int main()
{
	int size = 0;
	int range = 0;
	int lower = 0;
	int upper = 0;
	cout << "Input the number of elements to be inserted into the array" << endl;
	cin >> size;
	int *input_array=new int[size];
	cout << "Input range of elements to be inserted into array" << endl;
	cout << "Input the lower limit_";
	cin >> lower;
	cout << endl;
	cout << "Input the upper limit_";
	cin >> upper;
	cout << endl;
	range = (upper - lower) + 1;
	cout << "Input elements into the array" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> input_array[i];
	}
	cout << "Array elements before sorting are:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << input_array[i] << " ";
	}
	counting_sort(input_array, size, range);
	cout << "Array elements after sorting" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << input_array[i] << " ";
	}
	return 0;
}