function ProfileCard({ name, role, bio, imgUrl }) {
  return (
    <div
      style={{
        border: "2px solid #ccc",
        borderRadius: "12px",
        padding: "20px",
        width: "250px",
        textAlign: "center",
        background: "white",
        boxShadow: "0 4px 10px rgba(0,0,0,0.1)",
        transition: "transform 0.2s ease-in-out"
      }}
      onMouseEnter={(e) => e.currentTarget.style.transform = "scale(1.05)"}
      onMouseLeave={(e) => e.currentTarget.style.transform = "scale(1)"}
    >
      <img
        src={imgUrl}
        alt={name}
        style={{
          borderRadius: "50%",
          width: "100px",
          height: "100px",
          objectFit: "cover",
          marginBottom: "10px"
        }}
      />
      <h3>{name}</h3>
      <p style={{ color: "#777", fontSize: "14px" }}>{role}</p>
      <p style={{ fontSize: "13px", color: "#555" }}>{bio}</p>
    </div>
  );
}

export default ProfileCard;
