void bubbleSort(int arr[], int arrSize){

	// base case
	if (arrSize == 1) {
		return;
	}
	else {
		for (int i = 0; i < arrSize - 1; i++) {

			// check if right is less than left
			if (arr[i + 1] < arr[i]) {

				// swap 
				swap(arr[i], arr[i + 1]);
			}
		}
		// call again for smaller array
		bubbleSort(arr, arrSize - 1);
	}
}
