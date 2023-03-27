#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> stableInternships(vector<vector<int>> &interns, vector<vector<int>> &teams) {
  // Write your code here.

  vector<int> freeInterns(interns.size(), 0);
  
  for (int i = 0; i < interns.size(); i++) freeInterns[i] = i;
    

  vector<unordered_map<int,int>> internRankByTeam;
  
  for (int team = 0; team < interns.size(); team++) {
    
    unordered_map<int,int> internRank;
    
    for (int preference = 0; preference < interns.size(); preference++) {
      
      internRank[ teams[team][preference] ] = preference;
    }

    internRankByTeam.push_back(internRank);
  }

  
  unordered_map<int,int> teamIntern;
  
  vector<int> internCurrentPreference(interns.size(), 0);
  
  while(freeInterns.size() > 0) {
    int intern = freeInterns.back();
    int preference = internCurrentPreference[intern];
    
    if (preference == interns.size())  break;
     
    
    int team = interns[intern][preference];
    
    if (teamIntern.count(team) == 0) {
      
      teamIntern[team] = intern;
      freeInterns.pop_back();
    }
      
    else 
    {
      int assignedIntern = teamIntern[team];
      
      if (internRankByTeam[team][intern] < internRankByTeam[team][assignedIntern]) {
        
        freeInterns.pop_back();
        teamIntern[team] = intern;
        freeInterns.push_back(assignedIntern);
      }
    }
    internCurrentPreference[intern]++;
  }

  
  vector<vector<int>> result;  
  for (auto it : teamIntern)  result.push_back({it.second, it.first});
  
  return result;
}
