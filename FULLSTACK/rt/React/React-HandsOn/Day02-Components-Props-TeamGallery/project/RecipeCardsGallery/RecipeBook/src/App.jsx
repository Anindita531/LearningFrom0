import React from "react";
import RecipeCard from "./RecipeCard";

function App() {
  const recipes = [
    {
      title: "Pasta Alfredo",
      time: 25,
      difficulty: "Easy",
      imageUrl:
        "https://images.unsplash.com/photo-1603133872878-684f208fb84b?w=600",
      ingredients: ["Pasta", "Cream", "Cheese", "Garlic", "Butter"],
    },
    {
      title: "Veg Biryani",
      time: 45,
      difficulty: "Medium",
      imageUrl:
        "https://images.unsplash.com/photo-1601050690597-1b8a17d04a3a?w=600",
      ingredients: ["Rice", "Vegetables", "Spices", "Ghee"],
    },
    {
      title: "Chocolate Cake",
      time: 60,
      difficulty: "Hard",
      imageUrl:
        "https://images.unsplash.com/photo-1599785209796-86e8f3a0e2ab?w=600",
      ingredients: ["Flour", "Cocoa", "Sugar", "Eggs", "Butter"],
    }, {
      title: "Chocolate Cake",
      time: 60,
      difficulty: "Hard",
      imageUrl:
        "https://images.unsplash.com/photo-1599785209796-86e8f3a0e2ab?w=600",
      ingredients: ["Flour", "Cocoa", "Sugar", "Eggs", "Butter"],
    },
  ];

  return (
    <div>
      <h1 style={{ textAlign: "center", margin: "20px" }}>🍴 Recipe Gallery</h1>
      <div className="gallery">
        {recipes.map((recipe, index) => (
          <RecipeCard key={index} {...recipe} />
        ))}
      </div>
    </div>
  );
}

export default App;
