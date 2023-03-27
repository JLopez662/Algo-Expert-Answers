def nonConstructibleChange(coins):

    # Write your code here.
    coins.sort()

    maxChange = 0
    nonChange = 0

    for coin in coins:
        if(coin <= maxChange+1):
            maxChange +=coin
        
        else:
            nonChange = maxChange +1
            return nonChange
    
    return maxChange +1
    

    
