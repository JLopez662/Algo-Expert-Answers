import java.util.*;

class Program {

  public int nonConstructibleChange(int[] coins) 
  {
    Arrays.sort(coins);

    int maxChange = 0;
    int nonChange = 0;
    int coinTotal = coins.length;

    for(int i = 0; i < coinTotal; i++)
    {
        if(coins[i] <= maxChange+1)
        {
            maxChange += coins[i];
        }

        else
        {
            nonChange = maxChange +1;
            return nonChange;
        }
    }

    return maxChange +1;
  }
}
