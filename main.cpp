#include <iostream>
using namespace std;
void check0(int);

class div0:public exception{
	virtual const char* what() const throw(){
		return "Dived by zero";
	}
};
class fail:public exception{
	public:
	virtual const char* what() const throw(){
		cin.clear();
		cin.ignore(50,'\n');
		return "STUPID!! You need to input 2 intgers";
	}
};

void check0 (int x){
	//if(x==0) throw(x);
	if(x==0) throw div0();
}

int main(){
	
	int x,y;
	double d;
	int a;
	do{
		a=0;
		try{
			int i;

			cout<< "Enter 2 numbers: ";
			cin>>x>>y;

			/*if(!(cin>>x>>y)){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw fail();
			}
			*/

			if(cin.fail()){
				throw fail();
			}

			if(abs(x)>1000 || abs(y)>1000){
				throw "Value out of range";
			}
			check0(y);

			d=(double) x/y;
			cout<<"The result is " <<d<<endl;

			for(i=0;i<100;i++){
				cout<<"Allocating memory..."<<i<<endl;
				double *myarray = new double[1100000000];
			}
		}
			
		//not error not throw to catch

		/*catch(const char* error){
			cerr<<error<<endl;
			a=1;
			cin.clear();
			cin.ignore(50,'\n');
		
		}*///ถ้า error จะส่งมาที่ catch

		/*catch(const int e){
			switch(x){
				case 101: cerr<< "Incorrect numbers "<<endl; break;
				case 0: cerr<<"Divided by zero"<<endl; break;
			}	
			a=1;
			cin.clear();
			cin.ignore(50,'\n');
		}*/
		catch(exception &e){
			cerr<<e.what()<<endl;
			if(typeid(e)==typeid(bad_alloc)) a=0;
			else a=1;

		}
	}while(a==1);
	return 0;
}



  
