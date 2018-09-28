#include <bits/stdc++.h>
using namespace std;
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>

int main()
{
  long long int V,K;
  cin>>V;
  cin>>K;

  vector<pair<int,pair<int,int>>> Ys;
  vector<int> indices;

  for(int vert = 1; vert <= V; vert++)
	{
		int temp_vr = V*V + vert;
		for(int subg = 1; subg <= K; subg++)
		{
			Ys.push_back(make_pair(temp_vr,make_pair(vert,subg)));
      indices.push_back(temp_vr);
			temp_vr += V;
		}
	}



  ifstream infile("out");
  string line;
  vector<int> tokens;
  vector<vector<int>> parts;
  for(int i = 0; i< K; i++)
  {
    vector<int> tmp;
    parts.push_back(tmp);
  }

  while (getline(infile, line))
  {
    if(line.compare("UNSAT")==0)
    {
      cout<<0;
      break;
    }
    if(line.compare("SAT")==0)
    {
      continue;
    }

    stringstream check1(line);
    string intermediate;
    while(getline(check1, intermediate, ' '))
        tokens.push_back(stoi(intermediate));
  }

  vector<int>::iterator it;
  for(auto w: tokens)
  {
    if(w>0)
    {
      it = find (indices.begin(), indices.end(), w);
      if(it!=indices.end())
      {
        // cout << w << endl;
        int ind = it - indices.begin();
        pair<int,int> found = Ys.at(ind).second;
        // cout << found.first << " , " << found.second << endl;
        parts.at(found.second - 1).push_back(found.first);
      }
    }
  }
  int count = 1;
  for(auto w:parts)
  {
    cout <<  "#" << count++ << " " << w.size() << endl;
    for(auto c:w)
    {
      cout << c << " ";
    }
    cout << endl;
  }
}
