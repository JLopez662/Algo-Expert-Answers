#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights) 
{
  int size = redShirtHeights.size();

  sort(redShirtHeights.begin(), redShirtHeights.end());

  sort(blueShirtHeights.begin(), blueShirtHeights.end());

  cout << "Size: " << size << endl;
  cout << endl;

  for(int i = 0; i < size; i++)
  {
    cout << "redShirt: " <<redShirtHeights[i] << " vs blueShirt: " << blueShirtHeights[i] << endl;
    cout << endl;

    
    if(redShirtHeights[0] == blueShirtHeights[0])return false;
    
    if(redShirtHeights[0] > blueShirtHeights[0])
    {
      cout << "[FLAG]: >" << endl;
      if(redShirtHeights[i] <= blueShirtHeights[i])return false;
    }

    if(redShirtHeights[0] < blueShirtHeights[0])
    {
      cout << "[FLAG]: <" << endl;
      if(redShirtHeights[i] >= blueShirtHeights[i])return false;
    }
  }
  
  return true;
}

int main()
{
  vector<int> redShirtHeights = {3, 5, 6, 8, 2};

  vector<int> blueShirtHeights = {2, 4, 7, 5, 1};

  cout << classPhotos(redShirtHeights,blueShirtHeights) << endl;
}