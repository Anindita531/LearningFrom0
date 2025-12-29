function QuotesApp() {
    const quotes = [
        { q: "The best way to get started is to quit talking and begin doing.", a: "A" },
        { q: "Don’t let yesterday take up too much of today.", a: "s" },
        { q: "It’s not whether you get knocked down, it’s whether you get up.", a: "Q" },
        { q: "If you are working on something exciting, it will keep you motivated.", a: "q" }
    ];

    // random index তৈরি
    const [index, setIndex] = React.useState(0);

    function showNextQuote() {
        const next = Math.floor(Math.random() * quotes.length);
        setIndex(next);
    }
    function handleHover(e) {
        e.target.style.backgroundColor = "lightgreen";
    }
    function handleOut(e) {
        e.target.style.backgroundColor = "yellow";
    }

    return (
        <div className="Quote-Container">
            <div className="quote-box">
                <h2 onMouseOver={handleHover}
                    onMouseOut={handleOut}>"{quotes[index].q}"</h2>
                <p  >~{quotes[index].a}</p>
            </div>
            <button onClick={showNextQuote}

            >See Next</button>
        </div>

    );
}

ReactDOM.createRoot(document.getElementById("root")).render(<QuotesApp />);
