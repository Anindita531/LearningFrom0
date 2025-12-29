

function User({ name, age }) {
  return (
    <p>{name} - {age}</p>
  );
}

export default function  App() {
  const users = [
    { name: "Anindita", age: 21 }
    
  ];
  return (
    <div>
      {users.map((user, index) => <User key={index} name={user.name} age={user.age} />)}
    </div>
  );
}
