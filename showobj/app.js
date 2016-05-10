var express = require('express');
var path = require('path');
var favicon = require('serve-favicon');
var logger = require('morgan');
var cookieParser = require('cookie-parser');
var bodyParser = require('body-parser');
var routes = require('./app/routes/index');


var app = express();
app.listen(app.get('port'), function() {
  console.log('Server started: http://localhost:' + app.get('port') + '/');
});

// view engine setup
app.set('views', path.join(__dirname, 'app/views'));
app.set('view engine', 'jade');

// uncomment after placing your favicon in /public
//app.use(favicon(path.join(__dirname, 'public', 'favicon.ico')));
app.use(logger('dev'));
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', routes);

// catch 404 and forward to error handler
app.use(function(req, res, next) {
  var err = new Error('Not Found');
  err.status = 404;
  next(err);
});



// error handlers

// development error handler
// will print stacktrace
if (app.get('env') === 'development') {
  app.use(function(err, req, res, next) {
    res.status(err.status || 500);
    res.render('error', {
      message: err.message,
      error: err
    });
  });
}

// production error handler
// no stacktraces leaked to user


app.use(function(err, req, res, next) {
  res.status(err.status || 500);
  res.render('error', {
    message: err.message,
    error: {}
  });
});

var net = require('net');

var HOST = 'localhost';
var PORT = 8080;

var client = new net.Socket();
client.connect(PORT, HOST, function() {

  console.log('connected to server!');
  console.log('CONNECTED TO: ' + HOST + ':' + PORT);

});
client.on('data', function(data) {
  console.log(data.toString());
  client.end();
});
client.on('end', function() {
  console.log('disconnected from server');
});
// Add a 'close' event handler for the client socket
client.on('close', function() {
  console.log('Connection closed');
});

//   console.log('CONNECTED TO: ' + HOST + ':' + PORT);
//   // Write a message to the socket as soon as the client is connected, the server will receive it as message from the client
//   client.write('I am Chuck Norris!');
//   client.write('YOUHHHHHHHHH HAHAHHAHAHAAHHA chuck chuck chuk');
//
// });
//
//
//
// // Add a 'data' event handler for the client socket
// // data is what the server sent to this socket
// client.on('data', function(data) {
//
//   console.log('DATA: ' + data);
//   // Close the client socket completely
//   client.destroy();
//
// });
//

module.exports = app;
