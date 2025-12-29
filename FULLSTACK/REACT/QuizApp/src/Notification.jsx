function Notification({ message }) {
  if (!message) return null; // if message is empty, show nothing

  return (
    <div style={{
      marginTop: "20px",
      padding: "10px",
      backgroundColor: "#4caf50",
      color: "white",
      borderRadius: "5px",
      width: "fit-content"
    }}>
      {message}
    </div>
  );
}

export default Notification;
