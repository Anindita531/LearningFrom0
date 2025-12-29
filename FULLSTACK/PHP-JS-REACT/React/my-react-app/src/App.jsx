import React from "react";
import ReactDOM from "react-dom/client";

function App() {
  const name = "Anindita";
  return <h1>Hello, {name}!</h1>;
}

const root = ReactDOM.createRoot(document.getElementById("root"));
root.render(<App />);
