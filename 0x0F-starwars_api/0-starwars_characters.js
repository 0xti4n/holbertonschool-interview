#!/usr/bin/node

const args = process.argv.slice(2);
const request = require('request');

const url = `https://swapi-api.hbtn.io/api/films/${args[0]}`;

request.get(url, (error, response) => {
  if (error) {
    console.log(error);
  } else if (response.statusCode === 200) {
    const data = JSON.parse(response.body);
    data.characters.forEach(element => {
      request.get(element, (error, response) => {
        if (error) console.log(error);
        else if (response.statusCode === 200) {
          const dataCharacter = JSON.parse(response.body);
          console.log(dataCharacter.name);
        }
      });
    });
  }
});
