import { useEffect, useState } from "react";
import "./App.css";
import RandomJoke from "./components/RandomJoke";
import { FaLaughBeam, FaSmileWink, FaToggleOff, FaToggleOn } from "react-icons/fa";
import banglaJokes from "./data/banglaJokes";

function App() {
  const [joke, setJoke] = useState("");
  const [error, setError] = useState(null);
  const [loading, setLoading] = useState(false);
  const [isBangla, setIsBangla] = useState(true);

  // 📍 Fetch a Bengali joke
  const fetchBanglaJoke = () => {
    const randomIndex = Math.floor(Math.random() * banglaJokes.length);
    const selected = banglaJokes[randomIndex];
    console.log("Bangla joke fetched:", selected);
    setJoke(selected.joke);
  };

  // 🌐 Fetch an English joke
  async function fetchEnglishJoke() {
    setLoading(true);
    setError(null);
    try {
      const res = await fetch("https://v2.jokeapi.dev/joke/Any?type=single");
      if (!res.ok) throw new Error("Network response was not ok");
      const data = await res.json();
      setJoke(data.joke);
    } catch (err) {
      setError("Failed to fetch joke. Please try again.");
    } finally {
      setLoading(false);
    }
  }

  useEffect(() => {
    if (isBangla) fetchBanglaJoke();
    else fetchEnglishJoke();
  }, [isBangla]);

  useEffect(() => {
    const interval = setInterval(() => {
      if (isBangla) fetchBanglaJoke();
      else fetchEnglishJoke();
    }, 15000);
    return () => clearInterval(interval);
  }, [isBangla]);

  const handleToggle = () => {
    setIsBangla(!isBangla);
    setJoke("");
  };

  return (
    <div className="App">
      <h1>
        {isBangla ? "আসুন হাসির দুনিয়ায় 😄" : "Welcome to the World of Laughter 😄"}
      </h1>

      <button className="toggle-btn" onClick={handleToggle}>
        {isBangla ? (
          <FaToggleOn
            className="toggle-icon active"
            title="Switch to English"
          />
        ) : (
          <FaToggleOff
            className="toggle-icon"
            title="Switch to Bangla"
          />
        )}
        {isBangla ? "Switch to English 😎" : "বাংলা মোডে যান 😍"}
      </button>

      <div className="joke-section">
        {loading ? (
          <p>Loading...</p>
        ) : error ? (
          <p className="error">{error}</p>
        ) : (
          <RandomJoke
            data={{
              joke,
              type: "single",
              category: isBangla ? "বাংলা মজা" : "English Fun",
            }}
          />
        )}

        <div className="button-section">
          <button onClick={isBangla ? fetchBanglaJoke : fetchEnglishJoke}>
            {isBangla ? "আরেকটা জোকস দেখাও 😆" : "Get Another Joke 😂"}
          </button>
        </div>
      </div>
    </div>
  );
}

export default App;
