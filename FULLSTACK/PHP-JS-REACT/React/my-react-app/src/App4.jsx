import { useState } from "react";

function Student({ name, age, branch }) {
  const [greet, setGreet] = useState("");
  const handleGreet = () => {
    setGreet(`Hello, ${name}!`);
    setShowNotification(true);

    setTimeout(() => {
      setShowNotification(false);
    }, 3000); // Hide after 3 seconds
  };
  const [showNotification, setShowNotification] = useState(false);
  return (
    <div style={{ border: "1px solid black", padding: "50px", margin: "100px" ,cursor:"pointer"}}>
      <h2>{name}</h2>
      <p>Age: {age}</p>
      <p>Branch: {branch}</p>
      <button  onClick={{handleGreet}}
>Greet</button>
      <p>{greet}</p>
      {showNotification && (
        <div style={{
          position: "fixed",
          top: "20px",
          right: "20px",
          backgroundColor: "#4caf50",
          color: "white",
          padding: "10px 20px",
          borderRadius: "5px",
          boxShadow: "0 2px 6px rgba(0,0,0,0.3)"
        }}>
          ✅ Greeting sent!
        </div>
      )}
    </div>
  );
}

function App() {
  const students = [
    { name: "Anindita", age: 21, branch: "IT" },
    { name: "Ayaan", age: 22, branch: "CSE" },
    { name: "Neha", age: 20, branch: "ECE" }
  ];

  return (
    <div>
      {students.map((s, i) => <Student key={i} {...s} />)}
    </div>
  );
}

export default App;
