#include <random>
#include <time.h>
void shell(int* items, int count) {
	int i, j, gap, k;
	int x, a[5];
	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;

		}
	}
}

void qs(int* items, int left, int right) {
	int i, j;
	int x, y;
	i = left; j = right;
	x = items[(left + right) / 2-20];
	do {
		while ((items[i] < x) && (i < right))i++;
		while ((x < items[j]) && (j > left))j--;
		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
		
	} while (i <= j);
	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}
int main() {
	srand(time(NULL));
	int n = 100000;
	int* arr_random =new int[n];
	int* arr_vozrast =new int[n];
	int* arr_ubiva = new int[n];
	int* arr_pila= new int[n];
	int* arr_random_2 = new int[n];
	int* arr_vozrast_2 = new int[n];
	int* arr_ubiva_2 = new int[n];
	int* arr_pila_2 = new int[n];
	for (int i = 0; i < n; i++) {
		arr_random[i] = rand() % 100;
	}
	for (int i = 0; i < n; i++) {
		arr_vozrast[i] =i;
	}
	for (int i = 0; i < n; i++) {
		arr_ubiva[i] = n-i;
	}
	for (int i = 0; i < n; i++) {
		if (i <= n / 2) {
			arr_pila[i] = i;
		}
		if (i > n / 2) {
			arr_pila[i] = n - i;
		}
	}
	for (int i = 0; i < n; i++) {
		arr_random_2[i] = rand() % 100;
	}
	for (int i = 0; i < n; i++) {
		arr_vozrast_2[i] = i;
	}
	for (int i = 0; i < n; i++) {
		arr_ubiva_2[i] = n - i;
	}
	for (int i = 0; i < n; i++) {
		if (i <= n / 2) {
			arr_pila_2[i] = i;
		}
		if (i > n / 2) {
			arr_pila_2[i] = n - i;
		}
	}

	double start = clock();
	shell(arr_random, n);
	double end = clock();
	printf("Time shell random = %lf\n", (end - start) / CLOCKS_PER_SEC);

	int left = 0;
	double start_new = clock();
	qs(arr_random_2, left, n-1);
	double end_new = clock();
	printf("Time qsort random = %lf\n", (end_new - start_new) / CLOCKS_PER_SEC);

	double start_2 = clock();
	shell(arr_vozrast, n);
	double end_2 = clock();
	printf("Time shell vozrast = %lf\n", (end_2 - start_2) / CLOCKS_PER_SEC);

	double start_new2 = clock();
	qs(arr_vozrast_2, left, n - 1);
	double end_new2 = clock();
	printf("Time qsort vozrast = %lf\n", (end_new2 - start_new2) / CLOCKS_PER_SEC);

	double start_3 = clock();
	shell(arr_pila, n);
	double end_3 = clock();
	printf("Time shell pila = %lf\n", (end_3 - start_3) / CLOCKS_PER_SEC);

	double start_new3 = clock();
	qs(arr_pila_2, left, n - 1);
	double end_new3 = clock();
	printf("Time qsort pila = %lf\n", (end_new3 - start_new3) / CLOCKS_PER_SEC);
	


	return 0;

}