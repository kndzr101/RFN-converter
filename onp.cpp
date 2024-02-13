#include <iostream>
#include <cstring>

using namespace std;
#include "stacks.hpp"
int findPrecedence ( char op){
	if ( op == '+' || op == '-'){
		return 2;
	}
	else if ( op == '*' || op == '/'){
		return 3;
	}
	return 0;
}
int main(int argc, char* argv[]){
	outputStack ouStack;
	operatorStack opStack;
	
	ouStack.use = 0;

	opStack.use = 0;
	
	int precedence = 0;
	int prevPrecedence = 0;
	for(int i = 1 ;  i<argc ; i++){
		if (argv[i][0] == '+' || argv[i][0] == '-' || argv[i][0] == '*' || argv[i][0] == '/'){
			
			
			char currentOp = argv[i][0];	
			//cout << currentOp << endl;
			



			while ( opStack.topSign() !='('
			 && opStack.use > 0 && 
			 ( (findPrecedence(currentOp) <= opStack.topPrec()) ) ){
					char helper = opStack.topSign();
					cout << " helper: " << helper << endl;
					opStack.pop();
					ouStack.push(helper);
				}


			
			char foo = argv[i][0];
			opStack.push(foo);	
			//opStack.display();		

		}
		else{
			int tempSize  = strlen( argv[i]);	
			int value = 0;

			for ( int j  = 0 ; j < tempSize ; j++){
				value  = 10*value + (argv[i][j] - '0');
			}
				


			ouStack.push(value);
			
		}

	}

	
	opStack.display();

	while ( opStack.use > 0){
		char helper = opStack.topSign();
		opStack.pop();
		ouStack.push(helper);
	}
	cout << "output Stack: " << endl;

	ouStack.display();
	cout << "operator Stack: " << endl;
	opStack.display();
	return 0;

}
