#!/usr/bin/node

const args = process.argv.slice(2);
const request = require('request');

const url = `https://swapi-api.hbtn.io/api/films/${args[0]}`;

request.get(url, async (error, response) => {
  if (error) console.log(error);
  else if (response.statusCode === 200) {
    const data = JSON.parse(response.body).characters;
    for (let i = 0; i < data.length; i++) {
      const res = await getCharacter(data[i]);
      console.log(res);
    }
  }
});

function getCharacter (url) {
  const name = new Promise((resolve) => {
    request.get(url, (error, response) => {
      if (error) console.log(error);
      resolve(JSON.parse(response.body).name);
    });
  });
  return name;
}
