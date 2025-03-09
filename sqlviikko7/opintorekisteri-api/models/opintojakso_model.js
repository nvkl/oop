const db = require("../database");

const opintojakso = {
  getAll: function (callback) {
    return db.query("select * from opintojakso", callback);
  },
  getById: function (id, callback) {
    return db.query(
      "select * from opintojakso where idOpintojakso=?",
      [id],
      callback
    );
  },
  add: function (opintojakso, callback) {
    return db.query(
      "insert into opintojakso (Koodi,Nimi,Laajuus) values(?,?,?)",
      [opintojakso.Koodi, opintojakso.Nimi, opintojakso.Laajuus],
      callback
    );
  },
  delete: function (id, callback) {
    return db.query(
      "delete from opintojakso where idOpintojakso=?",
      [id],
      callback
    );
  },
  update: function (id, opintojakso, callback) {
    return db.query(
      "update opintojakso set Koodi=?, Nimi=?, Laajuus=? where idOpintojakso=?",
      [opintojakso.Koodi, opintojakso.Nimi, opintojakso.Laajuus, id],
      callback
    );
  },
};
module.exports = opintojakso;