#!/usr/bin/node

const request = require('request');

async function sw (id) {
  const url = `https://swapi-api.hbtn.io/api/films/${id}`;

  request(url, async function (err, response, body) {
    if (err) {
      console.log(err);
    } else {
      for (const ch of JSON.parse(body).characters) {
        const ret = () => {
          return new Promise((resolve, reject) => {
            request(ch, function (err, response, body) {
              if (err) {
                console.log(err);
              } else {
                resolve(JSON.parse(body).name);
              }
            });
          });
        };
        console.log(await ret());
      }
    }
  });
}

if (process.argv.length === 3) {
  sw(process.argv[2]);
}
