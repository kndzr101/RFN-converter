#include <iostream>
#include <cstring>

using namespace std;
#include "stacks.hpp"
int findPrecedence ( char op){
	if ( op == '+' || op == '-'){
		return 2;
	}
	else if ( op == 'x' || op == '/'){
		return 3;
	}
	else if ( op == '^'){
		return 4;
	}
	return 0;
}
bool isLeftAssociative ( char op){
	if ( op == '+' || op == '-' || op == 'x' || op == '/' ){
		return 1;
	}
	else if (op == '^'){
		return 0;
	}
	return 0;
}
int main(int argc, char* argv[]){
	outputStack ouStack;
	operatorStack opStack;
	
	//ouStack.use = 0;

	
	
	int precedence = 0;
	int prevPrecedence = 0;
	for(int i = 1 ;  i<argc ; i++){
		
		if (argv[i][0] == '+' || argv[i][0] == '-' || argv[i][0] == 'x' || argv[i][0] == '/' || argv[i][0] == '^'){
			
			
			char currentOp = argv[i][0];	
			//cout << currentOp << endl;
			



			while ( (opStack.use > 0 && opStack.topSign() != '[') &&
       		  ( (findPrecedence(currentOp) < opStack.topPrec()) || (
			   (findPrecedence(currentOp) == opStack.topPrec()) && isLeftAssociative(currentOp) )) ) {
					char helper = opStack.topSign();
					opStack.pop();
					ouStack.pushOnc(helper);
				}


			
			char foo = argv[i][0];
			opStack.pushOnc(foo);	
			//opStack.display();		

		}
		else if ( argv[i][0] == '['){
			opStack.pushOnc(argv[i][0]);
		}
		else if (argv[i][0] == ']'){
			while(opStack.topSign() != '[' ){
				if ( opStack.use == 0){
					cout << "major error!" << endl;
					break;
				}
			    char helper2 = opStack.topSign();
			    opStack.pop();
			    ouStack.pushOnc(helper2);
			}
			if ( opStack.topSign() == '['){
			opStack.pop(); //	erase a left parenthesis 
			}
		}
		else if ( isdigit( argv[i][0]) ){
			int tempSize  = strlen( argv[i]);	
			int value = 0;

			for ( int j  = 0 ; j < tempSize ; j++){
				value  = 10*value + (argv[i][j] - '0');

			}
				


			ouStack.pushOni(value);
			
		}
		else{
			cout << "bad input !" << endl;
			break;
		}

	}


	//opStack.display();
	// <<"opStack: " <<opStack.use <<endl;
	while ( opStack.use > 0 ){
		char helper = opStack.topSign();
		opStack.pop();
		ouStack.pushOnc(helper);
	}
	cout << "output Stack: " << endl;

	ouStack.display();
	return 0;

}
