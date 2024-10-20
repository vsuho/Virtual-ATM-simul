const db = require('../database');
const bcrypt = require('bcryptjs');


const card = {
  getAllCards(callback) {
    return db.query('SELECT * FROM card', callback);
  },

  addCard(newCard, callback) {
    bcrypt.hash(newCard.pin, 10, (err, hashedPin) => {
      if (err) {
        return callback(err);
      }
      
      return db.query(
        'INSERT INTO card (pin, cardNumber) VALUES (?, ?)',
        [hashedPin, newCard.cardNumber], 
        callback
      );
    });
  },
  getByCardNumber(cardNumber, callback) {
    
     return db.query('select id_account from card_account inner join card on card_account.id_card=card.id_card where cardNumber= ?', [cardNumber], callback);
    
  },

  getOneCard(id_card, callback) {
    return db.query('SELECT * FROM card WHERE id_card = ?', [id_card], callback);
  },

  deleteCard(id_card, callback) {
    return db.query('DELETE FROM card WHERE id_card = ?', [id_card], callback);
  },

  login(id_card, callback) {
    return db.query('SELECT pin FROM card WHERE id_card = ?', [id_card], callback);
  },

  cardTransactions(id_card, callback) {
    return db.query(
      'SELECT transaction_date, amount FROM transactions WHERE card_id = ?',
      [id_card],
      callback
    );
  }
};

module.exports = card;
