const express=require('express');
const router=express.Router();
const card=require('../models/card_model');

router.get('/',function(request, response){
    console.log("card route");
card.getAllCards(function(err, result){
    if(err){
        response.send(err);
    }
    else {
        response.json(result);
    }
 });
});

router.get('/:id',function(request, response){
    card.getOneCard(request.params.id, function(err, result){
        if(err){
            response.send(err);
        }
        else {
            response.json(result[0]);
        }
    })
});

router.get('/getId/:cardNumber', function(request, response){
    card.getByCardNumber(request.params.cardNumber, function(err, dbResult){
if(err){
    response.send(err);
}
else {
    response.json(dbResult);
}
})
});


router.post('/',function(request, response){
    card.addCard(request.body, function(err, result){
        if(err){
            response.send(err);
        }
        else {
            response.json(result.affectedRows);
        }
    })
});

router.put('/:id',function(request, response){
    card.updateCard(request.params.id, request.body, function(err, result){
        if(err){
            response.send(err);
        }
        else {
            response.json(result.affectedRows);
        }
    })
});

router.delete('/:id', function(request, response){
    card.deleteCard(request.params.id, function(err, result){
        if(err){
            response.send(err);
        }
        else {
            response.json(result.affectedRows);
        }
    });
});

module.exports=router;