const db=require("../database");

const card_account={
    getAllCardAccount(callback){
        return db.query("SELECT * FROM card_account", callback);
    },
    getOneCardAccount(id, callback){
        return db.query("SELECT id_account FROM card_account WHERE id_card=?",[id], callback);
    },
    addCardAccount(newCardAccount,callback){
        return db.query("INSERT INTO card_account(id_card, id_account) VALUES(?,?)", [newCardAccount.id_card, newCardAccount.id_account], callback);
    },
    updateCardAccount(id, updateCardAccount, callback){
        return db.query("UPDATE card_account SET id_card=?, id_account=?", [updateCardAccount.id_card, updateCardAccount.id_account], callback);
    },
    deleteCardAccount(id, callback){
        return db.query("DELETE FROM card_account WHERE id_account=?", [id], callback);
    }
   

}

module.exports=card_account;