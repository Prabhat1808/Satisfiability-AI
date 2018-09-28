#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <fstream>

using namespace std;

#define lli long long int;

int main(){
	lli V,E,K;
	cin>>V;
	cin>>E;
	cin>>K;
	string str = "";
	lli temp; 
	int x[(V*V)+1];
	lli v1,v2;
	for(int i=1;i<=V;i++){
		for(int j=i+1;j<=V;j++){
			x[V*(i-1)+j] = 0;
		}
	}
	for(int i=0;i<E;i++){
		cin>>v1;
		cin>>v2;
		if(v1<v2){
			x[V*(v1-1)+v2] = 1;	
		}
		else{
			x[V*(v2-1)+v1] = 1;	
		}
	}
	for(int i=1;i<=V;i++){
		for(int j=i+1;j<=V;j++){
			ostringstream str1;
			temp = V*(i-1)+j;
			str1 << temp;
			if(x[V*(i-1)+j] == 0){
				str = str + "-" + str1.str()+" 0\n";
			}
			else{
				str = str + str1.str()+" 0\n";
			}
		}
	}
	string str_temp = "";
	for(int i=1;i<=V;i++){
		for(int j=i+1;j<=V;j++){
			ostringstream str1,str2;
			temp = V*(i-1)+j;
			str1 << temp;
			str2<<temp;
			str = str + "-"+ str1.str();
			temp = V*V + V*K + (i-1)*V + j;
			str1<<temp;
			for(int k=1;k<=K;k++){
				str = str + " "+ str1.str();
				str_temp = str_temp + str2.str() + " -" + str1.str()+" 0\n";
				temp += V*V;
				str1<<temp;
			}
			str = str + " 0\n";
			str = str + str_temp;
		}
	}


}