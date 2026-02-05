# 🍲 Recipe Finder 2.0  
**Version:** v2.0.0

A full-stack recipe search application with Redis caching,  search, dark mode, and local favorites. Built using modern web technologies with performance optimization via server-side caching.

---

## 🚀 Features

- 🔍 Search recipes using TheMealDB API  
- ⚡ Redis caching for faster repeated searches  
- 🌙 Dark mode toggle  
- 🕒 Recent search history (LocalStorage)  
- ❤️ Favorite recipes saving  
- ⏳ Loading spinner  
- 📱 Responsive UI (Bootstrap 5)

---

## 🛠️ Tech Stack

### Frontend
- HTML5  
- CSS3  
- JavaScript (Vanilla)  
- Bootstrap 5  
- Web Speech API  

### Backend
- Node.js  
- Express.js  
- Axios  
- Redis  
- dotenv  
- CORS  

---

## 📂 Project Structure

```
recipe-finder-2.0/
├── client/
│   ├── index.html
│   ├── style.css
│   ├── script.js
│   └── assets/
│       └── spinner.gif
│
├── server/
│   ├── index.js
│   └── .env
│
├── package.json
└── README.md
```

---

## ⚙️ Setup Instructions

### 1️⃣ Clone Repository
```bash
git clone https://github.com/your-username/recipe-finder-2.0.git
cd recipe-finder-2.0
```

### 2️⃣ Install Backend Dependencies
```bash
cd server
npm install
```

### 3️⃣ Start Redis Server
```bash
redis-server
```

### 4️⃣ Run Backend
```bash
npm start
```

Backend runs at:
```
http://localhost:5000
```

### 5️⃣ Run Frontend
Open `client/index.html` in browser  
(or use Live Server)

---

## 🔗 API Endpoint

### Search Recipes
```
GET /search?query=<recipe_name>
```

---

## 🧠 Redis Caching Strategy

- Cache Key:  
  ```
  recipes:<query>
  ```
- Cache Duration:  
  ```
  3600 seconds (1 hour)
  ```

---

## 📜 License

MIT License

---

**Status:** Actively Maintained
