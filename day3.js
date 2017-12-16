function findManhattanDist(num){
  var gridSize = Math.ceil(Math.sqrt(num));
  var distFromEnd = gridSize * gridSize - num;
  // 2x2 center = [0][1]
  // 4x4 center = [1][2]
  // 6x6 center = [2][3]
  var yCoord = gridSize - 1;
  var xCoord = gridSize - distFromEnd - 1;
  var centerYCoord = gridSize / 2; 
  var centerXCoord = centerYCoord - 1;
  console.log("Coordinates: grid[" + xCoord + "][" + yCoord + "]");
  console.log("Center coordinates: grid[" + centerXCoord + "][" + centerYCoord + "]");
  console.log("Horizontal steps: " + (xCoord - centerXCoord));
  console.log("Vertical steps: " + (yCoord - centerYCoord));
  console.log("Total: " + ((xCoord - centerXCoord) + (yCoord - centerYCoord)));
}

function findSpiralSum(num){
  var spiralArray = [];
  var value = 0;
  var term = 0;
  var gridSize;

  while (term <= 1){
    spiralArray[term] = 1;
    term++
  }
  while (term <= 4){
  spiralArray[term] = spiralArray[term - 1] + spiralArray[0];
  term++;
  spiralArray[term] = spiralArray[term - 1] + spiralArray[term - 2] + spiralArray[0];
  term++;
  }
  while (term <= 10){
    for (var i = 0; i <= 1; i++){
      spiralArray[term] = spiralArray[term - 1] + spiralArray[i];
      term++;
      spiralArray[term] = spiralArray[term - 1] + spiralArray[term - 2] + spiralArray[i] + spiralArray[i + 1];
      term++;
      spiralArray[term] = spiralArray[term - 1] + spiralArray[i] + spiralArray[i + 1];
      term++
    }
  }
  while (term <= 18){
    for (i = 2; i <= 4; i += 2){
      spiralArray[term] = spiralArray[term - 1] + spiralArray[i];
      term++;
      spiralArray[term] = spiralArray[term - 1] + spiralArray[term - 2] + spiralArray[i] + spiralArray[i + 1];
      term++;
      spiralArray[term] = spiralArray[term - 1] + spiralArray[i] + spiralArray[i + 1] + spiralArray[i + 2];
      term++;
      spiralArray[term] = spiralArray[term - 1] + spiralArray[i + 1] + spiralArray[i + 2];
      term++;
    }
  }
  while (term <= 28){
    for (i = 6; i <= 9; i += 3){
      spiralArray[term] = spiralArray[term - 1] + spiralArray[i];
      term++;
      spiralArray[term] = spiralArray[term - 1] + spiralArray[term - 2] + spiralArray[i] + spiralArray[i + 1];
      term++;
      spiralArray[term] = spiralArray[term - 1] + spiralArray[i] + spiralArray[i + 1] + spiralArray[i + 2];
      term++;
      spiralArray[term] = spiralArray[term - 1] + spiralArray[i + 1] + spiralArray[i + 2] + spiralArray[i + 3];
      term++;
      spiralArray[term] = spiralArray[term - 1] + spiralArray[i + 2] + spiralArray[i + 3];
      term++;
    }
  }
  while (term <= 40){
    for (i = 12; i <= 16; i += 4){
      spiralArray[term] = spiralArray[term - 1] + spiralArray[i];
      term++;
      spiralArray[term] = spiralArray[term - 1] + spiralArray[term - 2] + spiralArray[i] + spiralArray[i + 1];
      term++;
      spiralArray[term] = spiralArray[term - 1] + spiralArray[i] + spiralArray[i + 1] + spiralArray[i + 2];
      term++;
      spiralArray[term] = spiralArray[term - 1] + spiralArray[i + 1] + spiralArray[i + 2] + spiralArray[i + 3];
      term++;
      spiralArray[term] = spiralArray[term - 1] + spiralArray[i + 2] + spiralArray[i + 3] + spiralArray[i + 4];
      term++;
      spiralArray[term] = spiralArray[term - 1] + spiralArray[i + 3] + spiralArray[i + 4];
      term++;
    }
  }
  while (term <= 54){
    for (i = 20; i <= 25; i += 5){
      spiralArray[term] = spiralArray[term - 1] + spiralArray[i];
      term++;
      spiralArray[term] = spiralArray[term - 1] + spiralArray[term - 2] + spiralArray[i] + spiralArray[i + 1];
      term++;
      spiralArray[term] = spiralArray[term - 1] + spiralArray[i] + spiralArray[i + 1] + spiralArray[i + 2];
      term++;
      spiralArray[term] = spiralArray[term - 1] + spiralArray[i + 1] + spiralArray[i + 2] + spiralArray[i + 3];
      term++;
      spiralArray[term] = spiralArray[term - 1] + spiralArray[i + 2] + spiralArray[i + 3] + spiralArray[i + 4];
      term++;
      spiralArray[term] = spiralArray[term - 1] + spiralArray[i + 3] + spiralArray[i + 4] + spiralArray[i + 5];
      term++;
      spiralArray[term] = spiralArray[term - 1] + spiralArray[i + 4] + spiralArray[i + 5];
      term++;
    }
  }
  while (term <= 70){
    for (i = 30; i <= 36; i += 6){
      spiralArray[term] = spiralArray[term - 1] + spiralArray[i];
      term++;
      spiralArray[term] = spiralArray[term - 1] + spiralArray[term - 2] + spiralArray[i] + spiralArray[i + 1];
      term++;
      spiralArray[term] = spiralArray[term - 1] + spiralArray[i] + spiralArray[i + 1] + spiralArray[i + 2];
      term++;
      spiralArray[term] = spiralArray[term - 1] + spiralArray[i + 1] + spiralArray[i + 2] + spiralArray[i + 3];
      term++;
      spiralArray[term] = spiralArray[term - 1] + spiralArray[i + 2] + spiralArray[i + 3] + spiralArray[i + 4];
      term++;
      spiralArray[term] = spiralArray[term - 1] + spiralArray[i + 3] + spiralArray[i + 4] + spiralArray[i + 5];
      term++;
      spiralArray[term] = spiralArray[term - 1] + spiralArray[i + 4] + spiralArray[i + 5] + spiralArray[i + 6];
      term++;
      spiralArray[term] = spiralArray[term - 1] + spiralArray[i + 5] + spiralArray[i + 6];
      term++;
    }
  }
  for (i = 0; i < spiralArray.length; i++){
    if (spiralArray[i] > num){
      return console.log(spiralArray[i]);
    }
  }
}

findManhattanDist(347991);
findSpiralSum(347991);