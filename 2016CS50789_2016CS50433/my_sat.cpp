#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>


using namespace std;

//#define lli long long int;

int main(int argc, char* argv[]){
	// vector<pair<int,pair<int,int>>> Ys;
	freopen(argv[1],"r",stdin);
	long long int V,E,K;
	cin>>V;
	cin>>E;
	cin>>K;
	// string str = "";
	long long int temp;
	// int x[(V*V)+1];
	long long int v1,v2;
	// for(int i=1;i<=V;i++){
	// 	for(int j=i+1;j<=V;j++){
	// 		x[V*(i-1)+j] = 0;
	// 	}
	// }

	vector<int> x((V*V)+1);
	// cout << "Created"

	for(long long int i=1;i<=V;i++){
		for(long long int j=i+1;j<=V;j++){
			x.at(V*(i-1)+j) = 0;
		}
	}
	// for(int i=0;i<E;i++){
	// 	cin>>v1;
	// 	cin>>v2;
	// 	if(v1<v2){
	// 		x[V*(v1-1)+v2] = 1;
	// 	}
	// 	else{
	// 		x[V*(v2-1)+v1] = 1;
	// 	}
	// }
	for(long long int i=0;i<E;i++){
		cin>>v1;
		cin>>v2;
		if(v1<v2){
			x.at(V*(v1-1)+v2) = 1;
		}
		else{
			x.at(V*(v2-1)+v1) = 1;
		}
	}

	ofstream myfile;
  	myfile.open (argv[2]);
  	myfile<< "p cnf ";

  	// long long int num_var = (V*(V-1))/2 + V*K + (V*(V-1)*K)/2 + V*(K*K - K);
  	long long int num_var = V*V + V*K + V*V*K + V*K*K;

		// cout << num_var;

  	myfile<<num_var;
  	myfile<<" ";
  	long long int num_clause = (V*(V-1)*(3*K+1))/2 + (V*(V-1)*(K+1))/2 + (3*V+1)*(K*K - K);

  	myfile<<num_clause;
  	myfile<<" 0\n";


	for(long long int i=1;i<=V;i++){
		for(long long int j=i+1;j<=V;j++){
			// ostringstream str1;
			temp = V*(i-1)+j;
			// str1 << temp;
			if(x.at(V*(i-1)+j) == 0){
				myfile << "-";
				myfile << temp;
				myfile << " 0\n";
				// str = str + "-" + str1.str()+" 0\n";
			}
			else{
				myfile << temp;
				myfile << " 0\n";
			}
		}
	}
	long long int temp1,temp2,temp3;
	// string str_temp = "";
	for(long long int i=1;i<=V;i++){
		for(long long int j=i+1;j<=V;j++){
			ostringstream my_str;
			// ostringstream str1,str2;
			temp1 = V*(i-1)+j;
			// str1 << temp;
			// str2<<temp;
			myfile << "-";
			myfile << temp1;

			// str = str + "-"+ str1.str();
			temp = V*V + V*K + (i-1)*V + j;
			// str1<<temp;
			// cout<<str1<<" it\n";
			for(long long int k=1;k<=K;k++){
				myfile << " ";
				myfile << temp;

				// str = str + " "+ str1.str();
				my_str<<temp1;
				my_str<<" -";
				my_str<<temp;
				my_str<<" 0\n";
				// str_temp = str_temp + str2.str() + " -" + str1.str()+" 0\n";
				temp += V*V;
				// str1<<temp;
			}
			//str = str + " 0\n";
			myfile<<" 0\n";
			myfile<< (my_str.str());
			//str = str + str_temp;
		}
	}


	for(long long int i=1;i<=V;i++){
		for(long long int j=i+1;j<=V;j++){
			// ostringstream str1,str2,str3;
			temp1 = V*V + i;
			temp2 = V*V + j;
			temp3 = V*V + V*K + (i-1)*V + j;
			// str1 << temp1;
			// str2<<temp2;
			// str3 << temp3;
			for(long long int k=1;k<=K;k++){
				myfile<<"-";
				myfile<<temp1;
				myfile<<" -";
				myfile<<temp2;
				myfile<<" ";
				myfile<<temp3;
				myfile<<" 0\n";

				myfile<<"-";
				myfile<<temp3;
				myfile<<" ";
				myfile<<temp1;
				myfile<<" 0\n";

				myfile<<"-";
				myfile<<temp3;
				myfile<<" ";
				myfile<<temp2;
				myfile<<" 0\n";

				// str = str + "-" + str1.str() + " -" + str2.str() + " " + str3.str() + " 0\n";
				// str = str + "-" + str3.str() + " " + str1.str() + " 0\n";
				// str = str + "-" + str3.str() + " " + str2.str() + " 0\n";
				temp1 += V;
				temp2 += V;
				temp3 += V*V;
				// str1<<temp1;
				// str2<<temp2;
				// str3<<temp3;
			}
		}
	}

	for(long long int k1=1;k1<=K;k1++){
		for(long long int k2=1;k2<=K;k2++){
			if(k1!=k2){
				// ostringstream str1;
				temp = V*V + V*K + V*V*K + (k1-1)*K + k2;
				// str1<<temp;
				myfile<<temp;
				//str = str + str1.str();
				for(long long int i=2;i<=V;i++){
					temp += K*K;
					// str1<<temp;
					myfile<<" ";
					myfile<<temp;
					//str = str + " " + str1.str();
				}
				//str = str + " 0\n";
				myfile<<" 0\n";
			}
		}
	}

	for(long long int k1=1;k1<=K;k1++){
		for(long long int k2=1;k2<=K;k2++){
			if(k1!=k2){
				//ostringstream str1,str2,str3;
				temp1 = V*V + (k1-1)*V + 1;
				temp2 = V*V + (k2-1)*V + 1;
				temp3 = V*V + V*K + V*V*K + (k1-1)*K + k2;
				//str1 << temp1;
				//str2<<temp2;
				//str3 << temp3;
				for(long long int i=1;i<=V;i++){

					myfile<<temp1;
					myfile<<" -";
					myfile<<temp2;
					myfile<<" ";
					myfile<<temp3;
					myfile<<" 0\n";

					myfile<<"-";
					myfile<<temp3;
					myfile<<" -";
					myfile<<temp1;
					myfile<<" 0\n";

					myfile<<"-";
					myfile<<temp3;
					myfile<<" ";
					myfile<<temp2;
					myfile<<" 0\n";

					// str = str + str1.str() + " -" + str2.str() + " " + str3.str() + " 0\n";
					// str = str + "-" + str3.str() + " -" + str1.str() + " 0\n";
					// str = str + "-" + str3.str() + " " + str2.str() + " 0\n";
					temp1 += 1;
					temp2 += 1;
					temp3 += K*K;
					// str1<<temp1;
					// str2<<temp2;
					// str3<<temp3;
				}
			}
		}
	}
	// cout<<str<<"\n";
	myfile.close();

	ofstream aux;
	aux.open (argv[3]);
	aux << V << " " << K << "\n";
	aux.close();
	//Generate my hash mappings
	// for(int vert = 1; vert <= V; vert++)
	// {
	// 	int temp_vr = V*V + vert;
	// 	for(int subg = 1; subg <= K; subg++)
	// 	{
	// 		Ys.push_back(make_pair(temp_vr,make_pair(vert,subg)));
	// 		temp_vr += V;
	// 	}
	// }
	// freopen("mappings.txt","w",stdout);
	// for(auto w: Ys)
	// {
	// 	cout << w.first << " - > " << w.second.first << " , " <<w.second.second << endl;
	// }
}
