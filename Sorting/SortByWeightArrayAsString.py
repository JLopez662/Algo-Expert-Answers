def order_weight(nums: str) -> str:

    numberList = nums.split()

    weightDictionary = {}

    for number in numberList:
        weight = sum(int(digit) for digit in number)
        weightDictionary[number] = weight

        #sorted by Weights
        sortedDictionary = sorted(weightDictionary.items(), key = lambda item : (item[1], item[0]))

        #new string made only of the keys already sorted
        result = ' '.join(sortedDictionary[i][0] for i in range(len(sortedDictionary)))

        return result

    print(order_weight('56 65 74 100 99 68 86 180 90'))
