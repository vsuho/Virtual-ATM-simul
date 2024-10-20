const db = require('../database');

const user = {
  getAll: function(callback) {
    return db.query('select * from user', callback);
  },
  getById: function(id, callback) {
    return db.query('select fname from user where id_user=?', [id], callback);
  },
  add: function(user, callback) {
    return db.query(
      'insert into user (fname,lname) values(?,?)',
      [user.fname, user.lname],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from user where id_user=?', [id], callback);
  },
  update: function(id, user, callback) {
    return db.query(
      'update user set fname=?,lname=? where id_user=?',
      [user.fname, user.lname, id],
      callback
    );
  }
};
module.exports = user;
