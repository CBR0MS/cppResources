void bubbleSort(int arr[], int SIZE_ARR) {

	for (int i = 1; i < SIZE_ARR; i++) {

		for (int j = SIZE_ARR - 1; j >= i; j--) {

			if (arr[j] < arr[j - 1]) {

				swap(arr[j], arr[j - 1]);
			}
		}
	}
}
