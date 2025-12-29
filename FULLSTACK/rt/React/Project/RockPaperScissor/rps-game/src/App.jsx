import { useState, useEffect } from "react";
import "./App.css";

function App() {
  const choices = ["Rock", "Paper", "Scissors"];
  const [userChoice, setUserChoice] = useState("");
  const [computerChoice, setComputerChoice] = useState("");
  const [message, setMessage] = useState("Make your move!");
  const [result, setResult] = useState("");
  const [animClass, setAnimClass] = useState("");
  const [userScore, setUserScore] = useState(0);
  const [computerScore, setComputerScore] = useState(0);
  const [round, setRound] = useState(1);
  const [gameOver, setGameOver] = useState(false);

  const handleUserChoice = (choice) => {
    if (gameOver) return;
    setUserChoice(choice);
    const randomChoice = choices[Math.floor(Math.random() * 3)];
    setComputerChoice(randomChoice);
  };

  useEffect(() => {
    if (!userChoice || !computerChoice) return;

    let outcome = "";
    if (userChoice === computerChoice) outcome = "Draw";
    else if (
      (userChoice === "Rock" && computerChoice === "Scissors") ||
      (userChoice === "Paper" && computerChoice === "Rock") ||
      (userChoice === "Scissors" && computerChoice === "Paper")
    )
      outcome = "Win";
    else outcome = "Lose";

    setResult(outcome);

    // Animate and update score
    if (outcome === "Win") {
      setMessage("🎉 You Win this round!");
      setUserScore((prev) => prev + 1);
      setAnimClass("flash-green");
    } else if (outcome === "Lose") {
      setMessage("💀 You Lose this round!");
      setComputerScore((prev) => prev + 1);
      setAnimClass("flash-red");
    } else {
      setMessage("🤝 It's a Draw!");
      setAnimClass("flash-yellow");
    }

    // Check round and reset or finish game
    const timer = setTimeout(() => {
      if (round < 5) {
        setRound((prev) => prev + 1);
        setUserChoice("");
        setComputerChoice("");
        setMessage("Next Round: Make your move!");
        setResult("");
        setAnimClass("");
      } else {
  setTimeout(() => {
    setGameOver(true);
    setAnimClass("");
    if (userScore > computerScore)
      setMessage("🏆 You win the session!");
    else if (computerScore > userScore)
      setMessage("💀 Computer wins the session!");
    else
      setMessage("🤝 It's a tie session!");
  }, 500);
}

    }, 2000);

    return () => clearTimeout(timer);
  }, [userChoice, computerChoice]);

  const resetGame = () => {
    setUserChoice("");
    setComputerChoice("");
    setMessage("Make your move!");
    setResult("");
    setAnimClass("");
    setUserScore(0);
    setComputerScore(0);
    setRound(1);
    setGameOver(false);
  };

  return (
    <div className={`container ${animClass}`}>
      <h1>Rock Paper Scissors</h1>
      <div className="session-info">
        <p>Round: {round} / 5</p>
        <p>🧍 You: {userScore} | 🤖 Computer: {computerScore}</p>
      </div>

      <div className="message-screen">{message}</div>

      <div className="choices">
        {choices.map((choice) => (
          <button
            key={choice}
            className="choice-btn"
            onClick={() => handleUserChoice(choice)}
            disabled={gameOver}
          >
            {choice}
          </button>
        ))}
      </div>

      <div className="results">
        <p><strong>You:</strong> {userChoice || "?"}</p>
        <p><strong>Computer:</strong> {computerChoice || "?"}</p>
      </div>

      {gameOver && (
        <button className="restart-btn" onClick={resetGame}>
          🔄 Play Again
        </button>
      )}
    </div>
  );
}

export default App;
