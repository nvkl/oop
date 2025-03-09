const db = require("../database");

const arviointi = {
  getAll: function (callback) {
    return db.query("select * from arviointi", callback);
  },
  getById: function (id, callback) {
    return db.query(
      "select * from arviointi where idArviointi=?",
      [id],
      callback
    );
  },
  add: function (arviointi, callback) {
    return db.query(
      "insert into arviointi (Arvosana,Päivamäärä) values(?,?)",
      [arviointi.Arvosana, arviointi.Päivämäärä],
      callback
    );
  },
  delete: function (id, callback) {
    return db.query(
      "delete from arviointi where idArviointi=?",
      [id],
      callback
    );
  },
  update: function (id, arviointi, callback) {
    return db.query(
      "update arviointi set Arvosana=?, Päivämäärä=? where idArviointi=?",
      [arviointi.Arvosana, arviointi.Paivamaara, id],
      callback
    );
  },
};
module.exports = arviointi;