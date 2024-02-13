#include <iostream>
using namespace std;
struct element{
	union{
	int intValue;
	char charValue;
	};
	bool isInt;
	
};
struct sign{
	union{
		char op;
		int precedence;
	};
};
class outputStack{
	public:

		element data[128];
		int use;
		outputStack() : use(0) {}
		void push(int value){
			data[use].intValue = value;
			data[use].isInt = 1;

			use++;
		}
		void push(char value){
			data[use].charValue = value;
			data[use].isInt = 0;
			use++;
		}
		void pop(){
			data[use].intValue = 0;
			data[use].charValue = 0;

			use--;
		}
		void display(){
			for ( int i = 0 ; i < use ;i++){
				if ( data[i].isInt == 1){
					cout << data[i].intValue << " ";
				}
				else{
					cout << data[i].charValue << " ";
				}

			}
			cout << endl;
		}


};
class operatorStack{
	public:
		sign signs[16];


		int use;
		//operatorStack() : use(0) {}
		int topPrec(){
			return signs[use-1].precedence;
		}
		char topSign(){
			return signs[use-1].op;
		}
		
		void push(char someSign){
			use++;
			signs[use-1].op = someSign;
			
			if ( someSign == '+' || someSign == '-'){
				signs[use-1].precedence = 2;
			}
			else if (someSign == '*' || someSign == '/'){
				signs[use-1].precedence = 3;
			}
		}
		void pop(){
			signs[use-1].op = 0;
			use--;
		}
		void display(){
			//cout <<signs[0].op<<endl;
			for ( int i = 0 ; i < use ; i++){
				cout << signs[i].op << " " ;
			}
		}

};
