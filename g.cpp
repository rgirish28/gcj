#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc, char **argv){
	
	if(argc<2){
		std::cout<<"Enter filename\n";
		return(0);
	}	
	char *file = argv[1];
	ifstream infile(file);
	int a,total,ctr,c=0;
	infile>>a;
	string b;
	while(infile >>a >> b){
		total = 0;
		ctr = 0;
		for(int i=0;i<=a;i++){
			while(i>total){
				ctr++;
				total++;
					
			}
			total += b[i]-'0';
		}
		cout<<"Case #"<<++c<<": "<<ctr<<endl;	
	}

}

