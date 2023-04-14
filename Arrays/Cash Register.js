function checkCashRegister(price, cash, cid) {

    const currencyUnits = [ 
      ["PENNY", 0.01],
      ["NICKEL", 0.05],
      ["DIME", 0.1],
      ["QUARTER", 0.25],
      ["ONE", 1],
      ["FIVE", 5],
      ["TEN", 10],
      ["TWENTY", 20],
      ["ONE HUNDRED", 100]
    ];
  
    let changeBal = cash - price;
  
    let totalCashAvail = 0;
    for(let currency of cid){totalCashAvail += currency[1];}
  
    if(totalCashAvail < changeBal){
      return {status: "INSUFFICIENT_FUNDS", change:[]};
    }
  
    else if(totalCashAvail == changeBal){
      return {status: "CLOSED", change: cid};
    }
  
    const change = [];
  
    for(let i = currencyUnits.length -1; i >=0; i--){
  
      const currencyName = currencyUnits[i][0];
      const currencyValue = currencyUnits[i][1];
      let currencyAmount = cid[i][1];
      let currencyCountOwed = 0;
  
      while(changeBal >= currencyValue && currencyAmount > 0){
        changeBal = Math.round(
          (changeBal - currencyValue) * 100) / 100;
        
        currencyAmount = Math.round(
          (currencyAmount - currencyValue) * 100) / 100;
        currencyCountOwed++;
      }
  
      if(currencyCountOwed > 0){
        change.push([currencyName, currencyValue * currencyCountOwed]);
      }
    }
  
    if(changeBal>0){
      return {status: "INSUFFICIENT_FUNDS", change: []};
    }
  
    return {status: "OPEN", change: change};

    return change;
  }
  
  checkCashRegister(19.5, 20, [["PENNY", 1.01], ["NICKEL", 2.05], ["DIME", 3.1], ["QUARTER", 4.25], ["ONE", 90], ["FIVE", 55], ["TEN", 20], ["TWENTY", 60], ["ONE HUNDRED", 100]]);