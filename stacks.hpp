#include <iostream>
using namespace std;
struct element{
	int intValue;
	char charValue;
	string stringValue;
	int isInt; //0 - char, 1 - int, 2 - string
	
};
struct sign{
	
		char op;
		int precedence;
		string functionName;
		bool isOp; // 0  - string, 1 - char
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
		void pushOns(string name){
			if (use >=128){
				cout << "Stack Overflow!"<<endl;
				return;
			}
			data[use].isInt =2;
			data[use].stringValue = name;
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
				if ( data[i].isInt == 0){
					//cout << "tutaj: " << endl;
					cout << data[i].charValue << " ";
				}
				else if (data[i].isInt == 2){
					cout << data[i].stringValue << " ";
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
			if (data[use-1].isInt == 0){
				temp.charValue = data[use-1].charValue;
				temp.intValue = 0;
				temp.isInt = 0;
				return temp;
			}
			if (data[use-1].isInt == 2){
				temp.stringValue = data[use-1].stringValue;
				temp.intValue = 0;
				temp.isInt = 2;
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
			if ( signs[use-1].isOp == 1){
			return signs[use-1].op;
			}

			return '\0';
			
		}
		string topFunc(){
			if (use-1 < 0){
				cout << "topFunc error!"<<endl;
				return "\0";

			}
			if (signs[use-1].isOp == 0){
				return signs[use-1].functionName;
			}
			else{
				cout << "some bad topFunc usage!"<<endl;
				return "\0";
			}
		}
		bool isFunction(){
			if (use-1 < 0){
				cout <<"isFunction error!"<<endl;
				return 0;
			}
			if ( signs[use-1].isOp == 0){
				return 1;
			}
			else{
				return 0;
			}
			return 0;
		}
		
		void pushOnc(char someSign){
			if ( use >=15){
				cout << "Stack Overflow! i"<<endl;
				return;
			}
			use++;
			signs[use-1].op = someSign;
			signs[use-1].isOp = 1;
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
		void pushOns(string name){
			if (use >= 15){
				cout << "Stack Overflow! s"<<endl;
				return;

			}
			use ++;
			signs[use-1].op = 0;
			signs[use -1].precedence = 0;
			signs[use-1].isOp = 0;
			signs[use-1].functionName = name;

		}
		void pop(){
			if ( use <=0){
				cout << "opStack Stack Underflow!"<<endl;
				return;
			}
			else{
			
			signs[use-1].op = 0;
			signs[use-1].functionName = "\0";
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
				if (signs[i].isOp==1){
				cout  << signs[i].op << " " ;
				}
				else if (signs[i].isOp ==0){
					cout << signs[i].functionName;
				}
			}
			/*while ( !oisEmpty()){
				cout << topSign();
				pop();
			}*/
		}

};
