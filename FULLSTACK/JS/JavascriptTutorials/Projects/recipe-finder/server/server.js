const express = require("express");
const cors = require("cors");

const fetch = (...args) =>
  import("node-fetch").then(({ default: fetch }) => fetch(...args));

const app = express();
app.use(cors());

app.get("/recipes", async (req, res) => {
  const { q } = req.query;

  const url = `https://www.themealdb.com/api/json/v1/1/search.php?s=${q}`;
  const response = await fetch(url);
  const data = await response.json();

  if (!data.meals) {
    return res.json({ meals: [] });
  }

  res.json(data);
});

app.listen(5000, () => {
  console.log("Server running at http://localhost:5000");
});
