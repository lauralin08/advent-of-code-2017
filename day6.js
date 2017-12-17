// count cycles required to get an array seen before
function cycleCount(blockList){
  var blockArray = blockList.split('\t');
  for (var i = 0; i < blockArray.length; i++){
    blockArray[i] = parseInt(blockArray[i]);
  }
  var index, largest, count = 0;
  var blockArrayBank = {};
  blockArrayBank[blockArray] = true;

  var seenBefore = false;
  while (!seenBefore){
    index = 0;
    largest = blockArray[0];
    for (i = 1; i < blockArray.length; i++){
      if (largest < blockArray[i]){
        largest = blockArray[i];
        index = i;
      }
    }
    blockArray[index] = 0;
    for (i = index + 1; i < (index + 1 + blockArray.length); i++){
      if (i >= blockArray.length){
        blockArray[i % blockArray.length] += Math.floor(largest / blockArray.length);
      } else {
        blockArray[i] += Math.floor(largest / blockArray.length);
      }
    }
    for (i = index + 1; i < (index + 1 + (largest % blockArray.length)); i++){
      if (i >= blockArray.length){
        blockArray[i % blockArray.length]++;
      } else {
        blockArray[i]++;
      }
    }
    
    count++;

    if (blockArrayBank[blockArray]){
      seenBefore = true;
    } else {            
      blockArrayBank[blockArray] = true;
    }    
  }
  console.log(count);
}

// count cycles between each loop of arrays seen before
function cycleCount2(blockList){
  var blockArray = blockList.split('\t');
  for (var i = 0; i < blockArray.length; i++){
    blockArray[i] = parseInt(blockArray[i]);
  }
  var index, largest, cycleLength, count = 0;
  var blockArrayBank = {};
  blockArrayBank[blockArray] = count;

  var seenBefore = false;
  while (!seenBefore){
    index = 0;
    largest = blockArray[0];
    for (i = 1; i < blockArray.length; i++){
      if (largest < blockArray[i]){
        largest = blockArray[i];
        index = i;
      }
    }
    blockArray[index] = 0;
    for (i = index + 1; i < (index + 1 + blockArray.length); i++){
      if (i >= blockArray.length){
        blockArray[i % blockArray.length] += Math.floor(largest / blockArray.length);
      } else {
        blockArray[i] += Math.floor(largest / blockArray.length);
      }
    }
    for (i = index + 1; i < (index + 1 + (largest % blockArray.length)); i++){
      if (i >= blockArray.length){
        blockArray[i % blockArray.length]++;
      } else {
        blockArray[i]++;
      }
    }
    
    count++;

    if (blockArrayBank[blockArray]){
      seenBefore = true;
      cycleLength = count - blockArrayBank[blockArray];
    } else {            
      blockArrayBank[blockArray] = count;
    }    
  }
  console.log(cycleLength);
}

cycleCount('14	0	15	12	11	11	3	5	1	6	8	4	9	1	8	4');
cycleCount2('14	0	15	12	11	11	3	5	1	6	8	4	9	1	8	4');