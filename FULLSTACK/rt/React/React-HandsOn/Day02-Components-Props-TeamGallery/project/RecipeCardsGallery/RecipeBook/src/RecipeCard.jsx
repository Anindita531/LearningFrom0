import React from "react";
import "./App.css";

function RecipeCard({ title, time, difficulty, imageUrl, ingredients }) {
  return (
    <div className="recipe-card">
      <img src={imageUrl} alt={title} className="recipe-img" />
      <h2>{title}</h2>
      <p>⏰ {time} mins</p>
      <p>🔥 Difficulty: {difficulty}</p>

      <div className="ingredients-box">
        <button className="show-btn">Show Ingredients</button>
        <ul className="ingredients-list">
          {ingredients.map((item, index) => (
            <li key={index}>{item}</li>
          ))}
        </ul>
      </div>
    </div>
  );
}

export default RecipeCard;
