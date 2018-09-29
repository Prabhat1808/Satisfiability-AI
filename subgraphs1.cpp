#include <bits/stdc++.h>
using namespace std;
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>

int main(int argc, char* argv[])
{

  ostringstream my_str;

  ifstream aux(argv[2]);
  long long int V,K,y_start;
  // cin>>V;
  // cin>>K;
  aux >> V >> K >> y_start;

  vector<pair<long long int,pair<int,int> > > Ys;
  vector<long long int> indices;

  // for(int vert = 1; vert <= V; vert++)
	// {
	// 	int temp_vr = V*V + vert;
	// 	for(int subg = 1; subg <= K; subg++)
	// 	{
	// 		Ys.push_back(make_pair(temp_vr,make_pair(vert,subg)));
  //     indices.push_back(temp_vr);
	// 		temp_vr += V;
	// 	}
	// }

int temp_vr;
for(int subg = 1; subg <= K; subg++)
{
  temp_vr = V*V + (subg-1)*V;
  for(int vert = 1; vert <= V; vert++)
  {
    temp_vr += 1;
    Ys.push_back(make_pair(temp_vr,make_pair(vert,subg)));
    indices.push_back(temp_vr);
  }
}

  // cout << "Generated Vertices: \n";
  // for(int i = 0; i< Ys.size(); i++)
  // {
  //   cout << Ys.at(i).first << " -->  " << Ys.at(i).second.first << " " << Ys.at(i).second.second << "\n";
  // }

  ifstream infile(argv[1]);
  string line;
  vector<int> tokens;
  vector<vector<int> > parts;
  for(int i = 0; i< K; i++)
  {
    vector<int> tmp;
    parts.push_back(tmp);
  }

  bool sat;
  freopen(argv[3],"w",stdout);
  while (getline(infile, line))
  {
    if(line.compare("UNSAT")==0)
    {
      cout<<0;
      sat = false;
      break;
    }
    if(line.compare("SAT")==0)
    {
      sat = true;
      continue;
    }

    stringstream check1(line);
    string intermediate;
    // while(getline(check1, intermediate, ' '))
    // {
    //     // tokens.push_back(stoi(intermediate));
    //     tokens.push_back(atoi(intermediate.c_str()));
    // }
    long long int temp_val = 0;
    while(getline(check1, intermediate, ' '))
    {
      temp_val = atoi(intermediate.c_str());
      if(abs(temp_val) >= y_start && abs(temp_val) < K*V + y_start + 1)
      {
        tokens.push_back(temp_val);
      }
      if(abs(temp_val) > y_start + K*V + 1)
      {
          break;
      }
    }
  }

// cout << Ys.size() << endl;
// cout << tokens.size() << endl;

  // cout << "Extracted Tokens: \n";
  // for(int i = 0; i < tokens.size(); i++)
  //   cout << tokens.at(i) << "\n";

  // freopen(argv[3],"w",stdout);
  vector<int>::iterator it;
  // for(int ind = 0; ind < tokens.size(); ind++)
  // {
  //   int w = tokens.at(ind);
  //   if(w>0)
  //   {
  //     it = find (indices.begin(), indices.end(), w);
  //     if(it!=indices.end())
  //     {
  //       // cout << w << endl;
  //       int ind = it - indices.begin();
  //       pair<int,int> found = Ys.at(ind).second;
  //       // cout << found.first << " , " << found.second << endl;
  //       parts.at(found.second - 1).push_back(found.first);
  //     }
  //   }
  // }

  int w;
  for(int ind = 0; ind < tokens.size(); ind++)
  {
    w = tokens.at(ind);
    if(w>0)
    {
      pair<int,int> found = Ys.at(w-y_start).second;
      parts.at(found.second - 1).push_back(found.first);
    }
  }

  if(sat)
  {
    int count = 1;
    for(int ind = 0; ind < parts.size(); ind++)
    {
      vector<int> w = parts.at(ind);
      cout <<  "#" << count++ << " " << w.size() << endl;
      for(int s = 0; s < w.size(); s++)
      {
        cout << w.at(s);
        if(s!=w.size()-1)
        {
          cout << " ";
        }
      }
      cout << endl;
    }
  }
}
