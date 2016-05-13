var mongoose = require('mongoose'),
  Schema = mongoose.Schema;

var schema = new Schema({
  // id:{type:String},
  // time:{type:String},
  // memory:{type:String},
  // taux:{type:Number, min: 0, max: 1000000 }
  cpu:{type: String},
  info:{type: String},
  time:{type: String},
  mem: {
    use:{type:String},
    tot:{type:String}
  }
});

// Nous exportons notre modèle avec comme nom "TauxDeCharge",
//'tauxDeCharge' sera le nom de notre "table"
exports.model = mongoose.model('TauxDeCharge', schema, 'tauxDeCharge');
