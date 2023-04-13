function rot13(str) {
    let key = 13;
    let wordToAscii = [];
  
    for (let i = 0; i < str.length; i++) {
      let c = str.charCodeAt(i);
      if (c >= 65 && c <= 90) {
        // uppercase letter
        if (c + key > 90) {
          wordToAscii.push(((c + key - 65) % 26) + 65);
        } else {
          wordToAscii.push(c + key);
        }
      } else if (c >= 97 && c <= 122) {
        // lowercase letter
        if (c + key > 122) {
          wordToAscii.push(((c + key - 97) % 26) + 97);
        } else {
          wordToAscii.push(c + key);
        }
      } else {
        // non-letter
        wordToAscii.push(c);
      }
    }
  
    let word = '';
    for (let i = 0; i < wordToAscii.length; i++) {
      word += String.fromCharCode(wordToAscii[i]);
    }
    return word;
  }
  
  console.log(rot13("SERR PBQR PNZC")); // should decode to the string FREE CODE CAMP
  