var mongoose = require('mongoose'),
  Schema = mongoose.Schema;

var schema = new Schema({
  id:{type:String},
  marque:{type:String},
  frequence:{type:Number, min: 0, max: 1 000 000}
});

// Nous exportons notre modèle avec comme nom "Entreprise",
//'entreprises' sera le nom de notre "table"
exports.model = mongoose.model('Cpu', schema, 'cpu');
