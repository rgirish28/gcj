#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

bool wayToSort(int i, int j) { return i > j; }

int main(int argc, char **argv){
	
	if(argc<2){
		std::cout<<"Enter filename\n";
		return(0);
	}	
	char *file = argv[1];
	ifstream infile(file);
	int a,largest,sum,c=0,index;
	infile>>a;
	int b[6];
	int count[10] = {0};
	while(infile >>a){
		
		std::fill( count, count+10, 0 );
		largest = 1;
		sum= 0;
		index = -1;
		for(int i=0;i<a;i++){
			infile >>b[i];
			count[b[i]-1]++;
		}

		for(int i=0;i<10;i++){
			if(count[i]>largest||(count[i]==largest&&(i+1)>index)){
				largest = count[i];
				index = i+1;
			}
		}

		
		std::sort(b,b+6, wayToSort);

		for(int i=0;b[i]>index;i++)
			sum++;
		if(sum==0){

		if(index==9||index==8||index==7)
			sum = sum+5;
		else if(index ==6||index==5)
			sum = sum+4;
		else if(index==4||index==3)
			sum = sum+3;
		else
			sum = sum+2;
		}
		else
			sum = sum+index;
		cout<<"Case #"<<++c<<": "<<sum<<endl;	
	}

}

