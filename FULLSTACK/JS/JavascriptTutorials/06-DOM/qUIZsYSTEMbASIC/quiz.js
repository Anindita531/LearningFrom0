 
  // Array of Questions (objects)
  let questions = [
    { q: "2 + 2 = ?", a: "4" },
    { q: "Capital of India?", a: "Delhi" },
    { q: "5 * 6 = ?", a: "30" }
  ];
console.log(typeof questions);
  let index = 0;
  let score = 0;

  // Function to load next question
  function loadQuestion() {
    if(index < questions.length){
      document.getElementById("question").innerText = questions[index].q;
      document.getElementById("answer").value = ""; // clear input
      document.getElementById("result").innerText = "";
    } else {
      document.getElementById("question").innerText = "🎉 Quiz Finished!";
      document.getElementById("answer").style.display = "none";
      document.getElementById("score").innerText = "Your Score: " + score + "/" + questions.length;
    }
  }

  // Function to check answer
  function checkAnswer() {
    let userAns = document.getElementById("answer").value.trim();
    if(userAns.toLowerCase() === questions[index].a.toLowerCase()){
      document.getElementById("result").innerText = "✅ Correct!";
      score++;
    } else {
      document.getElementById("result").innerText = "❌ Wrong! Answer: " + questions[index].a;
    }
    index++;
    setTimeout(loadQuestion, 1000); // wait 1 second before loading next question
  }

  // Start quiz
  loadQuestion();
 