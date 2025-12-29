import React, { useState } from "react";

function QuizApp() {
  const questions = [
    { q: "2 + 2 = ?", options: ["3", "4", "5", "6"], a: "4" },
    { q: "Capital of India?", options: ["Mumbai", "Delhi", "Kolkata", "Chennai"], a: "Delhi" },
    { q: "5 * 6 = ?", options: ["20", "25", "30", "35"], a: "30" }
  ];

  const [index, setIndex] = useState(0);
  const [score, setScore] = useState(0);
  const [result, setResult] = useState("");
  const [selected, setSelected] = useState("");

  function checkAnswer() {
    if (!selected) {
      setResult("⚠️ Please select an option!");
      return;
    }

    if (selected === questions[index].a) {
      setResult("✅ Correct!");
      setScore(score + 1);
    } else {
      setResult("❌ Wrong! Answer: " + questions[index].a);
    }

    setTimeout(() => {
      setResult("");
      setSelected("");
      setIndex(index + 1);
    }, 1000);
  }

  if (index >= questions.length) {
    return (
      <div>
        <h2>🎉 Quiz Finished!</h2>
        <p>Your Score: {score}/{questions.length}</p>
      </div>
    );
  }

  return (
    <div>
      <h2>{questions[index].q}</h2>
      <div>
        {questions[index].options.map((opt, i) => (
          <label key={i}>
            <input
              type="radio"
              name="option"
              value={opt}
              checked={selected === opt}
              onChange={(e) => setSelected(e.target.value)}
            />
            {opt}
          </label>
        ))}
      </div>
      <button onClick={checkAnswer}>Submit</button>
      <p>{result}</p>
      <p>Score: {score}</p>
    </div>
  );
}

export default QuizApp;
