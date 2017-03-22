int recMax(int arr[], int size, int ind) {

	static int max = arr[0];

	if (ind < size) {
	
		if (max < arr[ind]) {
			max = arr[ind];
		}
		int temp = recMax(arr, size, ind + 1);

		if (max < temp) {
			max = temp;
		}
	}
	return max;
}
