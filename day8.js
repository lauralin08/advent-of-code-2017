var fs = require('fs');

var input = fs.readFileSync('./day8Input.txt', 'utf8').split('\n');
var register = {};

function getRegisterValue(registerName) {
  if (!register[registerName]) {
    register[registerName] = 0;
    return 0;
  } else {
    return register[registerName];
  }
}

function evaluateCondition(registerName, operator, num) {
  switch (operator) {
    case '>':
      return (getRegisterValue(registerName) > num);
    case '<':
      return (getRegisterValue(registerName) < num);
    case '>=':
      return (getRegisterValue(registerName) >= num);
    case '<=':
      return (getRegisterValue(registerName) <= num);
    case '==':
      return (getRegisterValue(registerName) == num);
    case '!=':
      return (getRegisterValue(registerName) != num);
  }
}

var highest = 0;
for (var i = 0; i < input.length; i++) {
  var instructions = input[i].split(' ');
  if (evaluateCondition(instructions[4], instructions[5], instructions[6])) {
    if (instructions[1] === 'inc') {
      register[instructions[0]] = getRegisterValue(instructions[0]) + parseInt(instructions[2]);
    } else {
      register[instructions[0]] = getRegisterValue(instructions[0]) - parseInt(instructions[2]);
    }
    if (register[instructions[0]] > highest) {
      highest = register[instructions[0]];
    }
  }
}

var largest = register['buw'];
for (var key in register) {
  if (register[key] > largest) {
    largest = register[key];
  }
}

console.log(largest);
console.log(highest);