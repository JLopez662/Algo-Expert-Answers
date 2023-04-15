function convertToRoman(num) {
    const romanNumeral = {
      1000: 'M',
      900: 'CM',
      500: 'D',
      400: 'CD',
      100: 'C',
      90: 'XC',
      50: 'L',
      40: 'XL',
      10: 'X',
      9: 'IX',
      5: 'V',
      4: 'IV',
      1: 'I',
    };
  
    const keys = Object.keys(romanNumeral).map(Number).sort((a, b) => b - a);
    let romanStr = '';
  
    for (let i = 0; i < keys.length; i++) {
      const value = keys[i];
      while (num >= value) {
        romanStr += romanNumeral[value];
        num -= value;
      }
    }
  
    return romanStr;
  }
  
  console.log(convertToRoman(36)); // should return 'XXXVI'
  
  