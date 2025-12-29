import { useState } from "react";

function ThemeToggle() {
  const [dark, setDark] = useState(false);

  const themeStyle = {
    backgroundColor: dark ? "#222" : "#f0f0f0",
    color: dark ? "white" : "black",
    padding: "30px",
    textAlign: "center",
    borderRadius: "10px"
  };

  return (
    <div style={themeStyle}>
      <h2>{dark ? "Dark Mode 🌙" : "Light Mode ☀️"}</h2>
      <button onClick={() => setDark(!dark)}>Toggle Theme</button>
    </div>
  );
}

export default ThemeToggle;
