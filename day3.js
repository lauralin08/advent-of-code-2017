// find distance from coordinate to center of spiral grid
function findManhattanDist(num){
  var gridSize = Math.ceil(Math.sqrt(num));
  var distFromEnd = gridSize * gridSize - num;
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

// use array to model the spiral where each term is the sum of all neighbors
function findSpiralSum(num){
  var spiral = {};
  var output;
  spiral['0,0'] = 1;
  
  function getTerm(xCoord, yCoord){
    const RELATIVE_COORDS = [[1,0], [1,1], [0,1], [-1,1], [-1,0], [-1,-1], [0,-1], [1,-1]];
    var termCoord = xCoord + ',' + yCoord;
    spiral[termCoord] = 0;
    for (var i = 0; i < RELATIVE_COORDS.length; i++){
      if (spiral[(xCoord+RELATIVE_COORDS[i][0]) + ',' + (yCoord+RELATIVE_COORDS[i][1])]){
        spiral[termCoord] += spiral[(xCoord+RELATIVE_COORDS[i][0]) + ',' + (yCoord+RELATIVE_COORDS[i][1])];
      }
    }
    
    return (spiral[termCoord] > num);
  }

  var xCoord = 1, yCoord = 0;
  getTerm(xCoord, yCoord);

  while (spiral[xCoord + ',' + yCoord] < num){
    while (spiral[(xCoord-1) + ',' + yCoord]){
      yCoord++;
      getTerm(xCoord, yCoord);
    }
    while (spiral[xCoord + ',' + (yCoord-1)]){
      xCoord--;
      getTerm(xCoord, yCoord);
    }
    while (spiral[(xCoord+1) + ',' + yCoord]){
      yCoord--;
      getTerm(xCoord, yCoord);
    }
    while (spiral[xCoord + ',' + (yCoord+1)]){
      xCoord++;
      getTerm(xCoord, yCoord);
    }
  }
  
  for (var key in spiral){
    if (spiral[key] > num){
      console.log(spiral[key]);
      return spiral[key];
    }
  }
  
  console.log(spiral);
}

findManhattanDist(347991);
findSpiralSum(347991);