#!/usr/bin/node
const request = require('request');

request('https://swapi-api.hbtn.io/api/films/' + process.argv[2] + '/', async (err, res, body) => {
  if (err) {
    return console.error(err);
  }

  const charURLList = JSON.parse(body).characters;

  for (const charURL of charURLList) {
    await new Promise((resolve, reject) => {
      request(charURL, (err, res, body) => {
        if (err) {
          return console.error(err);
        }

        console.log(JSON.parse(body).name);
        resolve();
      });
    });
  }
});
