const mysql = require("mysql2");
const connection = mysql.createPool({
  host: "localhost",
  user: "root",
  password: "root",
  database: "test_db1",
});

module.exports = connection;