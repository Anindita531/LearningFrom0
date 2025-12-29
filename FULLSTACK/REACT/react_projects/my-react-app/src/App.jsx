import { useState } from 'react';
import React from 'react';
function Hello() {
  const name = "Anindita";
  return <h1>Hello, {name}! Welcome to React 💙</h1>;
}
function Welcome() {
  return <h2>Welcome to My First React App!</h2>;
}
function App() {
  const [count, setCount] = useState(0);
  return (
    <>
      <Hello />
      <Welcome />
      <h3>This is my first React component 😄</h3>

    </>
  );
}

export default App;
