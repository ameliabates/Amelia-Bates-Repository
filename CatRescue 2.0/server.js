const express = require('express');
const fs = require('fs');
const path = require('path');
const XLSX = require('xlsx');

const app = express();
const port = 3000;

app.use(express.static('public'));

app.get('/cats', (req, res) => {
  const filePath = path.join(__dirname, 'cats.xlsx');
  const workbook = XLSX.readFile(filePath);
  const sheetName = workbook.SheetNames[0];
  const worksheet = workbook.Sheets[sheetName];
  const json = XLSX.utils.sheet_to_json(worksheet);
  res.json(json);
});

app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
});
