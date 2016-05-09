var mongoose = require('mongoose'),
  Schema = mongoose.Schema;

var schema = new Schema({
  id:{type:String},
  date:{type:String},
  idCpu:{type:String},
  taux:{type:Number, min: 0, max: 1 000 000 }
});

// Nous exportons notre modèle avec comme nom "TauxDeCharge",
//'tauxDeCharge' sera le nom de notre "table"
exports.model = mongoose.model('TauxDeCharge', schema, 'tauxDeCharge');
