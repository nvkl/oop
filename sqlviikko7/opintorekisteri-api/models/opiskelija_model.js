const db = require("../database"); // PÄIVITÄ

const opiskelija = {
  getAll: function (callback) {
    return db.query("select * from opiskelija", callback);
  },
  getById: function (id, callback) {
    return db.query(
      "select * from opiskelija where idOpiskelija=?",
      [id],
      callback
    );
  },
  add: function (opiskelija, callback) {
    return db.query(
      "insert into opiskelija (Etunimi,Sukunimi,Luokkatunnus,Osoite) values(?,?,?,?)",
      [
        opiskelija.Etunimi,
        opiskelija.Sukunimi,
        opiskelija.Luokkatunnus,
        opiskelija.Osoite,
      ],
      callback
    );
  },
  delete: function (id, callback) {
    return db.query(
      "delete from opiskelija where idOpiskelija=?",
      [id],
      callback
    );
  },
  update: function (id, opiskelija, callback) {
    return db.query(
      "update opiskelija set Etunimi=?, Sukunimi=?, Luokkatunnus=?, Osoite=? where idOpiskelija=?",
      [
        opiskelija.Etunimi,
        opiskelija.Sukunimi,
        opiskelija.Luokkatunnus,
        opiskelija.Osoite,
        id,
      ],
      callback
    );
  },
};
module.exports = opiskelija;