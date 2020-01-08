#include <iostream>
using namespace std;

int arr[3];
int main()
{
	cin >> arr[0] >> arr[1] >> arr[2];
	if (arr[0] > arr[1]) swap(arr[0], arr[1]);
	if (arr[1] > arr[2]) swap(arr[1], arr[2]);
	if (arr[0] > arr[1]) swap(arr[0], arr[1]);
	cout << arr[1];
}
