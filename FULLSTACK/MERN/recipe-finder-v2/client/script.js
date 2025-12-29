const API = "http://localhost:5000/recipes?q=";

const searchInput = document.getElementById("searchInput");
const searchBtn = document.getElementById("searchBtn");
const results = document.getElementById("results");
const loader = document.getElementById("loader");
const historyBox = document.getElementById("history");
const themeBtn = document.getElementById("themeBtn");
const voiceBtn = document.getElementById("voiceBtn");

let favorites = JSON.parse(localStorage.getItem("favorites")) || [];

// SEARCH
searchBtn.onclick = () => searchRecipe();
searchInput.addEventListener("keydown", (e) => {
  if (e.key === "Enter") searchRecipe();
});

// MAIN SEARCH FUNCTION
async function searchRecipe() {
  const query = searchInput.value.trim();
  if (!query) return;

  loader.style.display = "block";
  results.innerHTML = "";

  // save history
  saveHistory(query);

  const res = await fetch(API + query);
  const data = await res.json();

  loader.style.display = "none";

  if (!data.meals) {
    results.innerHTML = "<h3>No recipes found 😢</h3>";
    return;
  }

  displayRecipes(data.meals);
}

// SHOW RECIPES
function displayRecipes(meals) {
  results.innerHTML = meals
    .map(
      (m) => `
      <div class="col-md-3">
        <div class="card p-2">
          <img src="${m.strMealThumb}" class="card-img-top">
          <h5>${m.strMeal}</h5>
          <button class="btn btn-success" onclick='addFavorite("${m.strMeal}")'>❤ Favorite</button>
        </div>
      </div>`
    )
    .join("");
}

// SAVE HISTORY
function saveHistory(term) {
  let history = JSON.parse(localStorage.getItem("history")) || [];
  history.unshift(term);
  history = [...new Set(history)].slice(0, 10);
  localStorage.setItem("history", JSON.stringify(history));
  showHistory();
}

function showHistory() {
  let history = JSON.parse(localStorage.getItem("history")) || [];
  historyBox.innerHTML = history
    .map((h) => `<span class="badge bg-secondary p-2" onclick="searchFromHistory('${h}')">${h}</span>`)
    .join("");
}

function searchFromHistory(q) {
  searchInput.value = q;
  searchRecipe();
}

showHistory();

// FAVORITES
function addFavorite(name) {
  if (!favorites.includes(name)) favorites.push(name);
  localStorage.setItem("favorites", JSON.stringify(favorites));
  alert("Added to favorites ❤️");
}

// THEME TOGGLE
themeBtn.onclick = () => {
  document.body.classList.toggle("dark");
};

// VOICE SEARCH
voiceBtn.onclick = () => {
  const recognition = new webkitSpeechRecognition();
  recognition.lang = "en-US";
  recognition.start();

  recognition.onresult = (e) => {
    searchInput.value = e.results[0][0].transcript;
    searchRecipe();
  };
};
