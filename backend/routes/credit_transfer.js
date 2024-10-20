const express = require('express');
const router = express.Router();
const credit =require('../models/credit_transfer_model');


router.post('/', 
function(request, response) {
  credit.credit(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult.affectedRows);
    }
  });
});

module.exports=router;