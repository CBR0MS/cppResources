void selectionSort(int arr[], int arrSize, int i) {

	// base case
	if ( i == arrSize - 1) {
		return;
	}
	else {
	
		int minInd = i;

		// find the min in the smaller array
		for (int j = i + 1; j < arrSize; j++) {

			// save the min index 
			if (arr[j] < arr[minInd]) {
				minInd = j;
			}
		}
		swap(arr[minInd], arr[i]);
		selectionSort(arr, arrSize, i + 1);
	}
}
