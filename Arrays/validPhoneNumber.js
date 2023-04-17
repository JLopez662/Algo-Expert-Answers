function telephoneCheck(str) {


    const regexPhones = [
      /^1?\s?\d{10}$/,
      /^1?\s?\d{3}-?\s?\d{3}-?\s?\d{4}$/,  
      /^1?\s?\(\d{3}\)\s?\d{3}-?\s?\d{4}$/, 
                            
    ];
  
    for (let i = 0; i < regexPhones.length; i++) {
      if (regexPhones[i].test(str)) {
        return true;
      }
    }
  
    return false;
  }
  