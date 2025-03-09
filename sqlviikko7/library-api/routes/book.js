const express = require("express");
const router = express.Router();
const book = require("../models/book_model");

router.get("/", function (request, response) {
  book.getAll(function (err, books) {
    if (err) {
      response.json(err);
    } else {
      console.log(books);
      response.json(books);
    }
  });
});

router.get("/:id", function (request, response) {
  book.getById(request.params.id, function (err, books) {
    if (err) {
      response.json(err);
    } else {
      response.json(books);
    }
  });
});

router.post("/", function (request, response) {
  book.add(request.body, function (err, books) {
    if (err) {
      response.json(err);
    } else {
      response.json(books);
    }
  });
});

router.delete("/:id", function (request, response) {
  book.delete(request.params.id, function (err, books) {
    if (err) {
      response.json(err);
    } else {
      response.json(books);
    }
  });
});

router.put("/:id", function (request, response) {
  book.update(request.params.id, request.body, function (err, books) {
    if (err) {
      response.json(err);
    } else {
      response.json(books);
    }
  });
});

module.exports = router;