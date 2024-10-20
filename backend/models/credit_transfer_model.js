const db = require('../database');


const credit_transfer={
    credit: function(transactions,callback) {
        return db.query(
          ' call credit_transfer(?,?,?,?)',
          [transactions.id_account,transactions.credit_limit, transactions.amount, transactions.transactionType],
          callback
        );
}
}

module.exports=credit_transfer;