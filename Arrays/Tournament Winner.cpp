#include <iostream>
#include <vector>
#include <map>
using namespace std;

//


string tournamentWinner(vector<vector<string>> competitions, vector<int> results) 
{
  // Write your code here.
  int round = 0;

  map<string, int> participants;

  int maxScore = 0;

  string winner;

  for(int i = 0; i < results.size(); i++)
  {
    if(results[i]==0) { participants[competitions[i][1]]++; }
      
    else{ participants[competitions[i][0]]++; }
  }

  for (auto im = participants.begin(); im != participants.end(); im++)
  {
    if(im->second > maxScore)
    {
      maxScore = im->second;
      winner = im->first;
    }
  }
  
  return winner;
