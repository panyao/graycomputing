var http = require('http');
var options = {method: 'HEAD', host: 'google.com', port: 80, path: '/'};
var req = http.request(options, function(res) {
    console.log(res.headers);
  }
);
req.end();