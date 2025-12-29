const searchInput = document.getElementById("searchInput");
const searchBtn = document.getElementById("searchBtn");
const results = document.getElementById("results");

// Fetch API data
async function searchRecipe() {
    const query = searchInput.value.trim();

    if (!query) {
        alert("Please type a recipe name!");
        return;
    }

    results.innerHTML = "<h4>Searching...</h4>";

    try {
        const response = await fetch(`https://www.themealdb.com/api/json/v1/1/search.php?s=${query}`);
        const data = await response.json();

        if (!data.meals) {
            results.innerHTML = "<h4>No recipes found 😢</h4>";
            return;
        }

        displayResults(data.meals);

    } catch (error) {
        results.innerHTML = "<h4>Error fetching data</h4>";
    }
}

// Render UI
function displayResults(meals) {
    results.innerHTML = "";

    meals.forEach(meal => {
        results.innerHTML += `
        <div class="col-md-4">
            <div class="card shadow">
                <img src="${meal.strMealThumb}" class="card-img-top">

                <div class="card-body">
                    <h5>${meal.strMeal}</h5>
                    <p class="text-muted">${meal.strArea} • ${meal.strCategory}</p>

                    <button class="btn btn-details" onclick="showDetails('${meal.idMeal}')">
                        View Details
                    </button>
                </div>
            </div>
        </div>`;
    });
}

// Show details inside modal
async function showDetails(id) {
    const response = await fetch(`https://www.themealdb.com/api/json/v1/1/lookup.php?i=${id}`);
    const data = await response.json();
    const meal = data.meals[0];

    const ingredients = [];

    for (let i = 1; i <= 20; i++) {
        const ing = meal[`strIngredient${i}`];
        const qty = meal[`strMeasure${i}`];
        if (ing) ingredients.push(`${ing} - ${qty}`);
    }

    alert(`
🍽 ${meal.strMeal}

Ingredients:
${ingredients.join("\n")}

Instructions:
${meal.strInstructions.substring(0, 400)}...
    `);
}

searchBtn.addEventListener("click", searchRecipe);
searchInput.addEventListener("keypress", (e) => {
    if (e.key === "Enter") searchRecipe();
});
