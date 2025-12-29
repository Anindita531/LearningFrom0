import { useState } from "react";

export default function App() {
  const [message, setMessage] = useState("");

  return (
    <div>
      <button onClick={() => setMessage("Hello, Anindita!")}>Click Me</button>
      <p>{message}</p>
    </div>
  );
}
