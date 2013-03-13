var zorba = require('./build/Release/zorba');
//var zorba = require('zorba');
try {
  var r = zorba.execute("Hello from Zorba for Node");
  console.log(r);
} catch (e) {
  console.log("error");
}
