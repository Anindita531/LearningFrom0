import { useState } from "react";
import Notification from "./Notification";

function App() {
  const [message, setMessage] = useState(""); // state for notification

  const showMessage = () => {
    setMessage("🚀 Hello Anindita! This is your notification!");
    
    // Optional: hide message after 3 seconds
    setTimeout(() => {
      setMessage("");
    }, 3000);
  };

  return (
    <div style={{ padding: "20px" }}>
      <h1>Screen Notification Example</h1>
      <button onClick={showMessage}>Show Notification</button>

      {/* Pass message as prop */}
      <Notification message={message} />
    </div>
  );
}

export default App;
