/**
 * Created by gregoire on 03/05/16.
 */
var net = require("net"),
    PassThroughStream = require('stream').PassThrough,
    stream = new PassThroughStream();

function getRandomArbitrary(min, max) {
    return Math.random() * (max - min) + min;
}

var server = net.createServer(function(socket) {
    console.log('server connected');
    
    socket.on('data', function (data) {
        console.log(JSON.parse(data.toString()));
        socket.write('merci. Est-ce bien ceci ? ' + data.toString() );
    });
    socket.write('Salut!');
    socket.on('end', function() {
        console.log('client disconnected');
    });
    // stream.on('data', function (d) {
    //     d = getRandomArbitrary(0,100).toString();
    //     socket.write(d);
    // });
    //socket.pipe(socket);
});


server.listen(8080, function() {
    console.log('server is listening');
});