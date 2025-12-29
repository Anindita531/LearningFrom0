import express from "express";
import cors from "cors";
import axios from "axios";
import { createClient } from "redis";
import dotenv from "dotenv";

dotenv.config();
const app = express();
app.use(cors());

const PORT = 5000;

// --- Redis Client ---
const redisClient = createClient({
  url: "redis://localhost:6379"  // your local Redis server
});

redisClient.connect()
  .then(() => console.log("Connected to Redis"))
  .catch(err => console.error("Redis Connection Error:", err));


// --- Search Route ---
app.get("/search", async (req, res) => {
  const query = req.query.query;

  if (!query) return res.status(400).json({ error: "Query is required" });

  const cacheKey = `recipes:${query.toLowerCase()}`;

  try {
    // 1️⃣ Check Redis Cache
    const cachedData = await redisClient.get(cacheKey);

    if (cachedData) {
      console.log("⚡ Returning Cached Results");
      return res.json(JSON.parse(cachedData));
    }

    // 2️⃣ Make API Call (using TheMealDB or any API)
    console.log("🌐 Fetching From External API");
    const response = await axios.get(
      `https://www.themealdb.com/api/json/v1/1/search.php?s=${query}`
    );

    const data = response.data;

    // 3️⃣ Save to Redis Cache for 1 hour
    await redisClient.setEx(cacheKey, 3600, JSON.stringify(data));

    res.json(data);
  } catch (error) {
    console.error("API Error:", error);
    res.status(500).json({ error: "Something went wrong" });
  }
});

// Start Server
app.listen(PORT, () => {
  console.log(`Server running at http://localhost:${PORT}`);
});
