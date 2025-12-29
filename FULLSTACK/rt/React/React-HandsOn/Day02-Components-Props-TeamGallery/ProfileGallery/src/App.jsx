import ProfileCard from "./components/ProfileCard";

function App() {
  const profiles = [
    {
      name: "Anindita Ghosh",
      role: "UX-Focused Developer,Frontend Engineer,Data Scientist",
      bio: "Loves designing meaningful user journeys through data-driven design.",
      imgUrl: "https://res.cloudinary.com/deowr5s2z/image/upload/v1745140260/bhrlxcr4yqbnqv3qcuad.jpg"
    },
    {
      name: "Ayaan ",
      role: "Creative Technologist",
      bio: "Believes in blending code and art to build beautiful experiences.",
      imgUrl: "https://res.cloudinary.com/deowr5s2z/image/upload/v1745185415/sample-avatar-1.jpg"
    },
    {
      name: "Riya Das",
      role: "Frontend Designer",
      bio: "Passionate about minimalistic and emotional design.",
      imgUrl: "https://res.cloudinary.com/deowr5s2z/image/upload/v1745185420/sample-avatar-2.jpg"
    }
  ];

  return (
    <div
      style={{
        display: "flex",
        justifyContent: "center",
        alignItems: "center",
        flexWrap: "wrap",
        gap: "20px",
        minHeight: "100vh",
        backgroundColor: "#f7f7f7"
      }}
    >
      {profiles.map((profile, index) => (
        <ProfileCard
          key={index}
          name={profile.name}
          role={profile.role}
          bio={profile.bio}
          imgUrl={profile.imgUrl}
        />
      ))}
    </div>
  );
}

export default App;
