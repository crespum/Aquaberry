var express = require('express');
var router = express.Router();

var rpi1 = false;
var rpi2 = false;
var title = 'Aquaberry control center';

/* GET home page. */
router.put('/rpi:id/:state', function(req, res, next) {
	if (req.params.id == 1) {
		rpi1 = req.params.state == 'on';
		title = 'Aquaberry control center: STATUS OK'
	} else if (req.params.id == 2) {
		rpi2 = req.params.state == 'on';
		title = 'Aquaberry control center: STATUS OK'
	}

	if (!rpi1 & !rpi2)
		title = 'Aquaberry control center: FAILURE!'

	res.send({ rpi1: rpi1, rpi2: rpi2 });
});

/* GET home page. */
router.get('/status', function(req, res, next) {
  res.render('index', { title: title, rpi1: rpi1, rpi2: rpi2 });
});

module.exports = router;
