/**
 * Created by gregoire on 04/05/16.
 */
var socket = io.connect('http://localhost:3000');

// initialisation recup

var optionsMem, str, opt;
socket.on('info', function (message) {

    // info cpu
    str = message.info;
    str = str.replace(/---.*$/,'');
    console.log(str);
    var currTime= parseInt(message.time);


    // on recupere la mémoire totale
    var mem = parseInt(message.mem.tot);
    var memMo = Math.round(mem/1000);
    str += " - " + memMo +"Mo";


// HIGH chart

$(function () {
    $(document).ready(function () {

        // initialisation des données à null
        function dataInit () {
            // generate an array of random data

            var data = [],
                time = (new Date()).getTime(),
                i;

            for (i = -19; i <= 0; i += 1) {
                data.push({
                    x: time + i * 1000,
                    y: null
                });
            }
            return data;
        }

        // Highcharts
        Highcharts.setOptions({
            global: {
                useUTC: false
            }
        });

        $('#container1').highcharts({
            chart: {
                zoomType: 'xy',
                animation: Highcharts.svg, // don't animate in old IE
                //animation:false,
                marginRight: 10,
                events: {
                    load: function () {
                        // set up the updating of the chart each second
                        var series = this.series[0];
                        var series1 = this.series[1];
                        socket.on('cpu', function (message) {
                            var x = (new Date()).getTime(); // current time
                            // on verifie si le serveur est connecté
                            if(currTime >= parseInt(message.time)){
                                console.log('Serveur Déconnecté');
                                $("#cont").text('SERVEUR DECONNECTE').css({color: 'red', 'font-weight': 'bold'});
                            }else{
                                $("#cont").text('SERVEUR CONNECTE').css({color: 'green', 'font-weight': 'bold'});
                                var yMem = parseInt(message.mem.use);
                                yMem = yMem/1000;
                                var yCpu = parseFloat(message.cpu);
                                series.addPoint([x, yCpu], false, true);
                                series1.addPoint([x , yMem], true, true);
                            }
                            currTime = parseInt(message.time);
                        });
                    }
                }
            },
            colors: ['#90ed7d', '#f7a35c', '#8085e9',
                '#f15c80', '#e4d354', '#2b908f', '#f45b5b', '#91e8e1'],
            title: {
                text: str
            },
            xAxis: {
                type: 'datetime',
                tickPixelInterval: 100,
                crosshair: true
            },
            yAxis: [{
                title: {
                    text: 'cpu charge',
                    style: {
                        color: Highcharts.getOptions().colors[2]
                    }
                },
                labels: {
                    format: '{value} %',
                    style: {
                        color: Highcharts.getOptions().colors[2]
                    }
                },
                max: 100,
                min: 0
            }, { // Secondary yAxis
                title: {
                    text: 'Mémoire',
                    style: {
                        color: Highcharts.getOptions().colors[3]
                    }
                },
                labels: {
                    format: '{value} Mo',
                    style: {
                        color: Highcharts.getOptions().colors[3]
                    }
                },
                max: memMo/1.1,
                min: 0
            }],
            tooltip: {
                shared: true
            },
            plotOptions: {
                line: {
                    marker: {
                        enabled: false
                    }
                },
                series: {
                    animation: 500
                }
            },
            legend: {
                enabled: true
            },
            exporting: {
                enabled: true
            },
            series: [{
                name: 'CPU',
                tooltip: {
                    valueSuffix: ' %',
                    valueDecimals: 2
                },
                data: dataInit()
            }, {
                name: 'Mémoire',
                yAxis: 1,
                tooltip: {
                    valueSuffix: ' Mo'
                },
                data: dataInit()
            }]
        });
    });
});


// GOOGLE cHART

    google.charts.load('current', {'packages':['gauge']});
    google.charts.setOnLoadCallback(drawChart);

    // options pour google chart
    var mem1 = mem-mem/4;
    var mem2 = mem-mem1/10;

    optionsMem = {
        min:0, max: mem,
        width: 500, height: 220,
        redFrom: mem2, redTo: mem,
        yellowFrom:mem1, yellowTo: mem2,
        greenFrom:0, greenTo:mem1,
        minorTicks: 25
    };

    function drawChart() {

        var data = google.visualization.arrayToDataTable([
            ['Label', 'Value'],
            ['CPU', 0]
        ]);

        var dataMem = google.visualization.arrayToDataTable([
            ['Label', 'Value'],
            ['Mémoire', 0]
        ]);

        var options = {
            min:0, max:100,
            width: 500, height: 220,
            redFrom: 90, redTo: 100,
            yellowFrom:75, yellowTo: 90,
            greenFrom:0, greenTo:75,
            minorTicks: 25
        };

        var chart = new google.visualization.Gauge(document.getElementById('chart_div'));
        var chartMem = new google.visualization.Gauge(document.getElementById('chart_div_mem'));
        //chart.draw(data, options);
        socket.on('cpu', function (message) {
            var yCpu = parseFloat(message.cpu);
            data.setValue(0, 1, Math.round(yCpu));
            chart.draw(data, options);

            var yMem = parseInt(message.mem.use);
            dataMem.setValue(0, 1, yMem);
            chartMem.draw(dataMem, optionsMem)
        });
        // setInterval(function() {
        //     data.setValue(0, 1, 75 + Math.round(25 * Math.random()));
        //     chart.draw(data, options);
        // }, 1000);
        // setInterval(function() {
        //     data.setValue(1, 1, Math.round(100 * Math.random()));
        //     chart.draw(data, options);
        // }, 1000);
    }
});

