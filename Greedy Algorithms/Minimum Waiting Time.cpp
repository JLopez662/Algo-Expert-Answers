using namespace std;

int sum = 0;


int minimumWaitingTime(vector<int> queries) 
{
  // Write your code here.

  sort(queries.begin(), queries.end());

  if(queries.size() == 1)
  {
    return sum;
  }
  
  for(int start = 0; start < queries.size()-1; start++)
  {
    sum+= queries[start];
  }

  queries.pop_back();

  return minimumWaitingTime(queries);

}