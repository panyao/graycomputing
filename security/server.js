var express = require('express');
var app = express();

var count = 0;

app.get('/', function(req, res) {
	count++;
  	res.send(count+ 'requests so far.');
});

app.listen(3000, function() {
  console.log('Node app is running on port 3000');
});

