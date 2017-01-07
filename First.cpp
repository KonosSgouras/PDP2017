#include <iostream>
#include <fstream> 
#include <vector>
#include <memory>
#include <stdio.h>      
#include <stdlib.h> 
#include <algorithm> 
#include <functional>  

using namespace std;

int M;

struct PlayerStats
{
	int stats;
	int id;

	
	
};
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int main ()
{
	int Test=0;
	int N;
    ofstream fout;
    ifstream fin;
    fin.open("input.txt");
    fout.open("output.txt");
    fin >> M ;
    
    vector<PlayerStats> Vector;
    allocator<int> al;
    int* a = al.allocate(10000);
    //Start EditingVector
    for(int i=0;i<M;i++)
	{
       fin>>N;
       cout<<N<<":"<<a[N]<<"\n";
       if(a[N]!=0)
	   {
	   	 for(int y=0;y<Vector.size();y++)
			{
	   	 	  if(Vector[y].id==N)
				  {
				  	Vector[y].stats++;
	   	 	  	    
				  }
			}
	   }
	   else
	   {
	   	if(a[N]==0)
	   {
	   	 PlayerStats PS;
	   	 PS.stats=0;
	   	 PS.id=N;
	   	 
	   	 a[N]=1;
       	 Vector.push_back(PS);
       	 
	   }
	   }
	   
    	
	   
	   	   
	}
	
	cout<<"\n";
	for(int i=0;i<Vector.size();i++)
	{
	   cout<<Vector[i].id<<" "<<Vector[i].stats<<"\n";
	   
	}
	
	//Start Qsort
	
		cout<<"\n";
	  int n;
	   
      qsort (&Vector[0], Vector.size(), sizeof(PlayerStats), compare);
      for (n=0; n<Vector.size(); n++)
	  {
      	cout<<Vector[n].id<<" "<<Vector[n].stats<<"\n";
	  }
	  n=0;
      for(int i=Vector.size()-1;i>-1;i--)
	  {
	  	
      	fout<<Vector[i].id<<" ";
	  }
		
	  
	  
	  
      fin.close();
      fout.close();
      return 0;
}




