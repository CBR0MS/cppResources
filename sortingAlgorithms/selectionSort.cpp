void selectionSort(int arr[], int SIZE_ARR) {

	for (int i = 0; i < SIZE_ARR - 1; i++) {

		int indexMin = i + 1;
		int assumedMin = arr[i];
		int subMin = arr[i + 1];

		for (int j = i + 2; j < SIZE_ARR; j++) {

			if (arr[j] < subMin) {

				subMin = arr[j];
				indexMin = j;
			}
		}
		if (assumedMin > subMin) {

			swap(arr[indexMin], arr[i]);
		}
	}
}
