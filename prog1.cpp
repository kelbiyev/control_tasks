#include <iostream>
#include <vector>
std::vector<std::vector<int>> TR (const std::vector<std::vector<int>>& matrix){	
	int m = matrix.size(); //rows
	int n = matrix[0].size(); //columns
	std::vector<std::vector<int>> matrix1(n , std::vector<int> (m));
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			matrix1[i][j] = matrix[j][i]; 
		}
	}
	return matrix1;
	
}
void print(const std::vector<std::vector<int>>& matrix){
	int m = matrix.size(); 
	int n = matrix[0].size();
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			std::cout<<matrix[i][j]<<" ";
		}
		std::cout<<"\n";
	}
	
}

int main (){
	int m;
	int n;
	std::cin >> m;
	std::cin >> n;
	std::vector<std::vector<int>> matrix(m , std::vector<int> (n));
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			matrix[i][j] = i + j; 
		}
	}


	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			std::cout<<matrix[i][j]<<" "; 
		}
		std::cout << "\n";
	}


	std::vector<std::vector<int>> tr_matrix(n , std::vector<int> (m));
	tr_matrix = TR(matrix);
	
	std::cout << "\n\n";
	
	print(tr_matrix);
	

	return 0;
}
