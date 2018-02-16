#include<iostream>

using namespace std;

int find_max_y(int * y_ptr, int size) {
	int max_value = y_ptr[0];
	for (int i = 1; i < size; i++) {
		if (y_ptr[i] > max_value) {
			max_value = y_ptr[i];
		}
	}
	return max_value;
}
int function_parabola(int x) {
	return x * x;
}

void fill_arrays(int * x_ptr, int * y_ptr, int from_x, int to_x) {
	int inner_iterator = 0;
	for (int i = from_x; i <= to_x; i++) {
		x_ptr[inner_iterator] = i;
		y_ptr[inner_iterator] = function_parabola(i);
		inner_iterator++;
	}
}
int main() {	
	int start_x = -4, finish_x = 4;
	int size = (finish_x - start_x) + 1;
	int optimized_size = (size % 2 == 0) ? (size + 1) : size;
	int * x_ptr = new int[size], *y_ptr = new int[size];
	fill_arrays(x_ptr, y_ptr, start_x, finish_x);
	int max_y = find_max_y(y_ptr, size);
	char ** board = new char * [max_y + 1];
	for (int i = 0; i < max_y + 1; i++) {
		board[i] = new char[optimized_size];
		for (int j = 0; j < optimized_size; j++) {
			board[i][j] = 0;
		}
	}
	int mid_x = size / 2;
	for (int i = 0; i < max_y + 1; i++) {
		for (int j = 0; j < optimized_size; j++) {
			board[i][j] = '*';
		}
	}
	for (int i = 0; i < size; i++) {
		int x_to_fill = mid_x + x_ptr[i];
		int y_to_fill = (max_y + 1 - 1) - (x_ptr[i] * x_ptr[i]);
		board[y_to_fill][x_to_fill] = '#';
	}
	for (int i = 0; i < max_y + 1; i++) {
		for (int j = 0; j < optimized_size; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << endl;

	//int * x_mas = new int[size];
	//int mid_kg = board[max_y - 1][mid_x];
	//for (int i = 0; i < size; i++) {
	//	if(x_ptr[i] < 0){ x_mas[i] = 4 + x_ptr[i]; }
	//	x_mas[4] = 4;
	//	if (x_ptr[i] > 0) { x_mas[i] = x_ptr[i] + 4; }
	//}
	//for (int i = 0; i < size; i++) {
	//	cout << x_mas[i] << " ";
	//}
	system("pause");
	return 0;
}