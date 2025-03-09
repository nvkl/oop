const db = require("../database");

const login = {
  checkPassword: function (username, callback) {
    return db.query(
      "select password from user where username = ?",
      [username],
      callback
    );
  },
};

module.exports = login;