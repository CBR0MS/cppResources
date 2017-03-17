void insertionSort(int arr[], int arrSize) {

	// base case
	if (arrSize == 1) {
		return;
	}
	else {

		// sort smaller array
		insertionSort(arr, arrSize - 1);

		int flag = arr[arrSize - 1];
		int i = arrSize - 2;

		// move elements larger than flag right
		while (i >= 0 && arr[i] > flag) {
			arr[i + 1] = arr[i];
			i--;
		}
		arr[i + 1] = flag;
	}
	return;
}
