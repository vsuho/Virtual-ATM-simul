const express=require("express");
const router=express.Router();
const card_account=require("../models/card_account_model");

router.get("/", function(request, response){
    card_account.getAllCardAccount(function(err, result){
        if(err){
            response.send(err);
        }
        else{
            response.send(result);
        }      
    });
});

router.get("/:id", function(request, response){
    card_account.getOneCardAccount(request.params.id, function(err, result){
        if(err){
            response.send(err);
        }
        else {
            response.json(result);
        }
    })
});

router.post("/", function(request, response){
    card_account.addCardAccount(request.body, function(err, result){
        if(err){
            response.send(err);
        }
        else {
            response.send(result.affectedRows);
        }
    })
});

router.put("/", function(request, response){
    card_account.updateCardAccount(request.params.id, request.body, function(err, result){
        if(err){
            response.send(err);
        }
        else {
            response.send(result.affectedRows);
        }
    })
});

router.delete("/:id", function(request, response){
    card_account.deleteCardAccount(request.params.id, function(err, result){
        if(err){
            response.send(err);
        }
        else {
            response.send(result.affectedRows)
        }
    });
});



module.exports=router;