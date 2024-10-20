const db = require('../database');


const debit_transfer={
    debit: function(transactions, callback) {
        return db.query(
          ' call debit_transfer(?,?,?)',
          [transactions.id_account, transactions.amount, transactions.transactionType],
          callback
        );
}
}

module.exports=debit_transfer;