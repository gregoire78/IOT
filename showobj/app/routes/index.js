var express = require('express');
var router = express.Router();

//controller
var board = require('../controllers/Board');
/* GET users listing. */
router.get('/', board.index);

module.exports = router;