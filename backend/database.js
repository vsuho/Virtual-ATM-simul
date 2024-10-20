const mysql = require('../backend/node_modules/mysql2');
const connection = mysql.createPool({
  host: '127.0.0.1',
  user: 'bankuser',
  password: 'bankpass',
  database: 'bank'
});
module.exports = connection;




