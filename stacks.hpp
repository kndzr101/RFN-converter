#include <iostream>
using namespace std;
struct element{
	int intValue;
	char charValue;
	bool isInt;
	
};
struct sign{
	
		char op;
		int precedence;
};
class outputStack{
	public:

		element data[128];
		int use;
		outputStack(){
			use = 0;
		}
		void pushOni(int value){
			if ( use >= 128){
				cout << "stack Overflow" <<endl;
				return;
			}
			data[use].intValue = value;
			data[use].isInt = 1;

			use++;
		}
		void pushOnc(char value){
			if (use >= 128){
				cout << "Stack Overflow!"<<endl;
				return;
			}
			data[use].charValue = value;
			data[use].isInt = 0;
			use++;
		}
		void pop(){
			//data[use].intValue = 0;
			//data[use].charValue = 0;
			if ( use <=0){
				cout << "Stack Undeflow! "<<endl;
				return;
			}
			use--;
		}
		void display(){
			for ( int i = 0 ; i < use ;i++){
				if ( data[i].isInt == 1){
					cout << data[i].intValue << " ";
				}
				else{
					//cout << "tutaj: " << endl;
					cout << data[i].charValue << " ";
				}

			}
			cout << endl;
			/*while ( !isEmpty()){
				if ( top().isInt == 1){
					cout << top().intValue;
				}
				else if (top().isInt == 0){
					cout << top().charValue;

				}
				else{
					cout << "display Error"<<endl;
					break;
				}
				pop();
			}
			*/
		}
		element top(){
			if ( use-1 < 0){
				cout << "Top Error!"<<endl;

			}
			element temp;
			if ( data[use-1].isInt == 1){
				temp.charValue = 0;
				temp.intValue = data[use-1].intValue;
				temp.isInt = 1;
				return temp;
			}
			else{
				temp.charValue = data[use-1].charValue;
				temp.intValue = 0;
				temp.isInt = 0;
				return temp;
			}
			
		}
		bool isEmpty(){
			if ( use <=0){
				return 1;
			}
			else{
				return 0;
			}
		}


};
class operatorStack{
	public:
		sign signs[16];


		int use;
		operatorStack(){
			use = 0;
		}
		int topPrec(){
			if ( use-1 < 0){
				cout << "topPrec error!"<<endl;
				return 0;
			}
			//cout << "topPrec: " << signs[use-1].precedence<<endl;
			return signs[use-1].precedence;
		}
		char topSign(){
			if ( use-1 < 0){
				cout << "topSign error!"<<endl;
				return 0;
			}
			//cout << "top Sgn: " << signs[use-1].op << endl;
			return signs[use-1].op;
		}
		
		void pushOnc(char someSign){
			if ( use >=15){
				cout << "Stack Overflow! i"<<endl;
				return;
			}
			use++;
			signs[use-1].op = someSign;
			//cout << signs[use-1].op << endl;
			//cout << "someSign: " << someSign << endl;
			
			if ( someSign == '+' || someSign == '-'){
				signs[use-1].precedence = 2;
			}
			else if (someSign == 'x' || someSign == '/'){
				signs[use-1].precedence = 3;
			}
			else if ( someSign == '^'){
				signs[use-1].precedence = 4;
			}
		}
		void pop(){
			if ( use <=0){
				cout << "opStack Stack Underflow!"<<endl;
				return;
			}
			else{
			
			signs[use-1].op = 0;
			use--;
			}
		}
		bool oisEmpty(){
			if ( use<=0){
				return 1;
			}
			else{
				return 0;
			}
		}
		void display(){
			//cout <<signs[0].op<<endl;
			for ( int i = 0 ; i < use ; i++){
				//cout <<"prec: "<< signs[i].precedence<<endl;
				cout  << signs[i].op << " " ;
			}
			/*while ( !oisEmpty()){
				cout << topSign();
				pop();
			}*/
		}

};
