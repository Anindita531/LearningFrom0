function RandomJoke({ data }) {
  if (!data || !data.joke) return null;

  return (
    <div className="random-joke">
      <p>
        <i>Type:</i> {data.type}
      </p>
      <p>
        <i>Category:</i> {data.category}
      </p>
      <p className="joke-text">{data.joke}</p>
    </div>
  );
}

export default RandomJoke;
