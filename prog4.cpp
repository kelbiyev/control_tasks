#include <iostream>
#include <deque>
#include <string>

void doTrain(int num , std::deque<int>& dq , std::string line){
	//auto iter1 = dq.begin();
	//auto iter2 = dq.end();
	
	//dq.erase(iter1 ,  );
	
	if(line == "+l"){
		dq.push_front(num);
	}
	else if(line == "+r"){
		
		dq.push_back(num);
	}
	else if(line == "-l"){	
		auto iter1 = dq.begin();
		auto iter2 = dq.begin() + num;
		dq.erase(iter1,iter2);
	}
	else if(line == "-r"){
		auto iter1 = dq.end();
		auto iter2 = dq.end() - num;
		dq.erase(iter1,iter2);
	}
}



int main(){
	std::deque <int> dq;//{1 , 4 , 6 , 8 , 10};
	std::string line;
	int num;
	
	while(std::cin >> line >> num){
		
		doTrain(num , dq , line);
		
		}
	if (dq.size() == 0){
		std::cout<<"empty";
	}
	else{	
		for(int x: dq){
			std::cout<<x<<" ";
		}
		std::cout<<"\n";
	}
	return 0;
}	
