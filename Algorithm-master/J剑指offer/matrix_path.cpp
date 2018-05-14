//矩阵中的路径 回溯法
#include<iostream>
using namespace std;

bool has_path_core(char* matrix, int rows, int cols, int row, 
	int col, const char* str, int& path_length, bool* visited)
{
	if ('\0' == str[path_length])
	{
		return true;
	}
	bool has_path = false;
	if (row >= 0 && row < rows && col >= 0 && col < cols
		&& matrix[row * cols + col] == str[path_length]
		&& !visited[row * cols + col])
	{
		++path_length;
		visited[row * cols + col] = true;

		has_path = has_path_core(matrix, rows, cols, row, col - 1, str, path_length, visited)
			|| has_path_core(matrix, rows, cols, row - 1, col, str, path_length, visited)
			|| has_path_core(matrix, rows, cols, row, col + 1, str, path_length, visited)
			|| has_path_core(matrix, rows, cols, row + 1, col, str, path_length, visited);

		if (!has_path)
		{
			--path_length;
			visited[row * cols + col] = false;
		}
	}
	return has_path;
}

bool has_path(char* matrix, int rows, int cols, char* str)
{
	if (NULL == matrix || rows < 1 || cols < 1 || NULL == str)
	{
		return false;
	}
	bool *visited = new bool[rows * cols];
	memset(visited, 0, rows * cols);

	int path_length = 0;
	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < cols; ++col)
		{
			if (has_path_core(matrix, rows, cols, row, col, str, path_length, visited))
			{
				return true;
			}
		}
	}

	delete[] visited;
	return false;
}

int main(void)
{
	char matrix[3 * 4] = {
		'a', 'b', 't', 'g',
		'c', 'f', 'c', 's',
		'j', 'd', 'e', 'h'
	};

	char *str0 = "abfb";
	char *str1 = "bfce";

	cout << has_path(matrix, 3, 4, str0) << endl;
	cout << has_path(matrix, 3, 4, str1) << endl;

	return 0;
}