#include <iostream>
#include <vector>

template <typename T>

void Duplicate(std::vector<T>& v){
	v.reserve(2*size(v));
	for (auto it = v.begin() ; it != v.end(); ++it)
		v.push_back(*it);

} 



int main (){
	
	std::vector<int> v {4,5,6};
	Duplicate(v);
	
	for (int el:v)
		std::cout<<el<<" "; 
	
	std::cout<<"\n";
	return 0;
}

