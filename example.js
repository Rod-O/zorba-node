console.log("Step 1");
var zorba = require('./build/Release/zorba');
//var zorba = require('zorba');
try {
  var r = zorba.execute("1+1");
} catch (e) {
  console.log("error");
}
console.log("Step 3");

//console.log(zorba.execute("'Hello Node from Zorba!'"));
