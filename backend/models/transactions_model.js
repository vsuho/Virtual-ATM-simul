const db = require('../database');

const transactions = {
  getAll: function(callback) {
    return db.query('select id_account, amount, transactionType, date_format(transactionDate, "%d.%m.%Y:%h.%i.%s") as transactionDate from transactions', callback);
  },
  getById: function(id, callback) {
    return db.query('select id_account, amount, transactionType, date_format(transactionDate, "%d.%m.%Y:%h.%i.%s") as transactionDate from transactions where id_account=?', [id], callback);

  },

  
  add: function(transactions, callback) {
    return db.query(
      'insert into transactions (id_account, amount, transactionType, transactionDate) values(?,?,?,?)',
      [transactions.id_account, transactions.amount, transactions.transactionType, transactions.transactionDate],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from transactions where id_transactions=?', [id], callback);
  },
  update: function(id, transactions, callback) {
    return db.query(
      'update transactions set id_account=?,amount=?,transactionType=?,transactionDate=? where id_transactions=?',
      [transactions.id_account, transactions.amount, transactions.transactionType, transactions.transactionDate, id],
      callback
    );
  }
};
module.exports = transactions;