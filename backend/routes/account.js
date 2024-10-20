const express=require('express');
const router=express.Router();
const account=require('../models/account_model');

router.get('/',function(request, response){
    account.getAll(function(err, result){
        if(err){
            response.json(err);
        }
        else{
            response.json(result);
        }
    })
});

router.get('/:id',
function(request, response){
    account.getById(request.params.id, function(err, dbResult){
        if(err){
            response.json(err);
        }
        else{
            response.json(dbResult[0].id_user);
        }
    })
});
router.get('/user/:id',
function(request, response){
    account.getByUserId(request.params.id, function(err, dbresult){
        if(err){
            response.json(err);
        }
        else{
            response.json(dbresult);
        }
    })
});
router.get('/balance/:id',
function(request, response){
    account.getBalanceById(request.params.id, function(err, dbresult){
        if(err){
            response.json(err);
        }
        else{
            response.json(dbresult);
        }
    })
});

router.post('/',
function(request,response) {
    account.add(request.body, function(err, result){
        if(err){
            response.json(err);
        }
        else{
            response.json(result);
        }
    });
});

router.delete('/:id',
function(request, response){
    account.delete(request.params.id, function(err,result){
        if(err){
            response.json(err);
        }
        else{
            response.json(result);
        }
    });
});

router.put('/:id',
function(request, response){
    account.update(request.params.id, request.body, function(err, result){
        if(err){
            response.json(err);
        }
        else{
           response.json(result);
        }
    });
});

module.exports=router;


