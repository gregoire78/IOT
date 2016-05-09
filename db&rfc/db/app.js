var express = require('express');
var mongoose = require('mongoose');

mongoose.connect('mongodb://localhost/db', function(err){
  if (err) {throw err; }
});

var app = express();

app.get('/', function (req, res) {
  res.send('Server db');
});

var server = app.listen(3000, function () {
  var host = server.address().address;
  var port = server.address().port;

  console.log('Server database listening at http://%s:%s', host, port);
});
