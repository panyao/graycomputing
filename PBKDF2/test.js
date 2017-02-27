const crypto = require('crypto');

var key;
var start = new Date();
for(var i=1; i<=10; i++){
	key = crypto.pbkdf2Sync('secret', 'salt', 1000, 512, 'sha512');
}
var end = new Date() - start;

console.log("Execution time: %dms", end);

console.log(key.toString('hex'));  // 'c5e478d...1469e50'
