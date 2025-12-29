import { useState } from "react";
import "./styles.css";

function LoginForm() {
  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");
  const [error, setError] = useState("");

  const handleSubmit = (e) => {
    e.preventDefault();
    if (!email.includes("@") || password.length < 6) {
      setError("Invalid email or password must be at least 6 characters");
    } else {
      setError("");
      alert(`Welcome ${email.split("@")[0]}! 🎉`);
      setEmail("");
      setPassword("");
    }
  };

  return (
    <form className="form" onSubmit={handleSubmit}>
      <label>Email:</label>
      <input
        type="email"
        value={email}
        onChange={(e) => setEmail(e.target.value)}
      />

      <label>Password:</label>
      <input
        type="password"
        value={password}
        onChange={(e) => setPassword(e.target.value)}
      />

      {error && <p className="error">{error}</p>}

      <button type="submit">Login</button>
    </form>
  );
}

export default LoginForm;
