/**
 * Created by gregoire on 04/05/16.
 */
$(function () {
    $(document).ready(function () {

        Highcharts.setOptions({
            global: {
                useUTC: false
            }
        });

        $('#container1').highcharts({
            chart: {
                animation: Highcharts.svg, // don't animate in old IE
                marginRight: 10,
                events: {
                    load: function () {

                        // set up the updating of the chart each second
                        var series = this.series[0];
                            var socket = io.connect('http://localhost:3000');
                            socket.on('message', function (message) {
                                var x = (new Date()).getTime(); // current time
                                var y = parseFloat(message);
                                console.log(message);
                                series.addPoint([x, y], true, true);
                            });
                    }
                }
            },
            colors: ['#90ed7d', '#f7a35c', '#8085e9',
                '#f15c80', '#e4d354', '#2b908f', '#f45b5b', '#91e8e1'],
            title: {
                text: 'CPU charge'
            },
            xAxis: {
                type: 'datetime',
                tickPixelInterval: 150
            },
            yAxis: {
                title: {
                    text: '%'
                },
                plotLines: [{
                    value: 0,
                    width: 1,
                    color: '#808080'
                }],
                max: 100,
                min: 0
            },
            tooltip: {
                formatter: function () {
                    return '<b>' + this.series.name + '</b><br/>' +
                        Highcharts.dateFormat('%Y-%m-%d à %H:%M:%S', this.x) + '<br/>' +
                        Highcharts.numberFormat(this.y, 2) + "%";
                }
            },
            plotOptions: {
                line: {
                    marker: {
                        enabled: false
                    }
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
                data: (function () {
                    // generate an array of random data
                    var data = [],
                        time = (new Date()).getTime(),
                        i;

                    for (i = -19; i <= 0; i += 1) {
                        data.push({
                            x: time + i * 1000,
                            y: Math.random() * (100 - 0) + 0
                        });
                    }
                    return data;
                }())
            }]
        });
    });
});

google.charts.load('current', {'packages':['gauge']});
google.charts.setOnLoadCallback(drawChart);
function drawChart() {

    var data = google.visualization.arrayToDataTable([
        ['Label', 'Value'],
        ['Memory', 80],
        ['CPU', 55],
        ['Network', 68]
    ]);

    var options = {
        width: 400, height: 120,
        redFrom: 90, redTo: 100,
        yellowFrom:75, yellowTo: 90,
        minorTicks: 5
    };

    var chart = new google.visualization.Gauge(document.getElementById('chart_div'));

    chart.draw(data, options);

    setInterval(function() {
        data.setValue(0, 1, 75 + Math.round(25 * Math.random()));
        chart.draw(data, options);
    }, 1000);
    setInterval(function() {
        data.setValue(1, 1, Math.round(100 * Math.random()));
        chart.draw(data, options);
    }, 1000);
    setInterval(function() {
        data.setValue(2, 1, Math.round(100 * Math.random()));
        chart.draw(data, options);
    }, 1000);
}
