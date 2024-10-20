const db=require('../database');

const account={
    getAll(callback){
        return db.query('SELECT * FROM account', callback);
 
    },
    getById: function(id, callback){
        return db.query('SELECT id_user FROM account WHERE id_account=?', [id], callback);
   
    },
    getByUserId: function(id, callback){
        return db.query('SELECT accountNumber FROM account WHERE id_user=?', [id], callback);
   
    },
    getBalanceById:function(id, callback){
        return db.query('SELECT balance FROM account WHERE id_account=?', [id], callback);
   
    },

    add: function(account, callback){
        return db.query('INSERT INTO account (accountNumber,balance,id_user) values(?,?,?)', [account.accountNumber,account.balance,account.id_user], callback);

    },
    delete: function(id, callback){
        return db.query('DELETE FROM account WHERE id_account=?', [id], callback);
        
    },
    update: function(id, account, callback){
        return db.query('UPDATE account SET accountNumber=?,balance=?,id_user=? WHERE id_account=?', [account.accountNumber, account.balance, account.id_user, id], callback);

    }

};

module.exports=account;

