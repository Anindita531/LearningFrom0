// src/App.jsx
function App() {
  const name = "Anindita Ghosh";
  const role = "Aspiring UX-Focused Developer";
  const bio = "Passionate about blending design and data for meaningful experiences.";
  const imgUrl = "https://res.cloudinary.com/deowr5s2z/image/upload/v1745140260/bhrlxcr4yqbnqv3qcuad.jpg";

  return (
    <div style={{
      display: "flex",
      justifyContent: "center",
      alignItems: "center",
      height: "100vh",
      background: "#d30a0a9a"

    }}>
      <div style={{
        border: "2px solid #d30505ff",
        borderRadius: "16px",
        padding: "20px",
        width: "280px",
        textAlign: "center",
        boxShadow: "0 0 10px rgba(0,0,0,0.1)",
        background: "#fff"
      }}>
        <img
          src={imgUrl} alt="profile" style={{ borderRadius: "50%", width: "150px", height: "150px", 
            objectFit: "cover", display: "block", margin: "0 auto 15px", borderColor: "#d30505ff", borderStyle: "solid", borderWidth: "2px",
            transition: "transform 0.3s ease",
          }} 
            onMouseEnter={(e) => e.currentTarget.style.transform = "scale(1.05)"} 
            onMouseLeave={(e) => e.currentTarget.style.transform = "scale(1)"}

        />
        <h2>{name}</h2>
        <h4>{role}</h4>
        <p>{bio}</p>
      </div>
    </div>
  );
}

export default App;
