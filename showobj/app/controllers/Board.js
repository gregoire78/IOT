/**
 * Created by gregoire on 10/05/16.
 */
require('../models/tauxDeCharge');

var mongoode = require('mongoose'),
    Taux = mongoode.model('TauxDeCharge');

var Board = {
    index:function (req, res) {
        Taux.find({}, function (err, cpu) {
            if (err) throw err;
            //console.log(cpu);
            res.render('index', { cpu : cpu});
        });
        
    }
};

module.exports = Board;