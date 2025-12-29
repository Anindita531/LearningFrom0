  // Array of Questions (objects with options)
  let questions = [
    { 
      q: "2 + 2 = ?", 
      options: ["3", "4", "5", "6"], 
      a: "4" 
    },
    { 
      q: "Capital of India?", 
      options: ["Mumbai", "Delhi", "Kolkata", "Chennai"], 
      a: "Delhi" 
    },
    { 
      q: "5 * 6 = ?", 
      options: ["20", "25", "30", "35"], 
      a: "30" 
    }
  ];

  let index = 0;
  let score = 0;

  // Function to load next question
  function loadQuestion() {
    if(index < questions.length){
      document.getElementById("question").innerText = questions[index].q;
      
      // Clear old options
      let optionsDiv = document.getElementById("options");
      optionsDiv.innerHTML = "";

      // Create radio buttons for options
      questions[index].options.forEach(opt => {
        lebtn = document.createElement("div");
        btn.innerHTML = `
          <label>
            <input type="radio" name="option" value="${opt}"> ${opt}
          </label>
        `;
        optionsDiv.appendChild(btn);
      });

      document.getElementById("result").innerText = "";
    } else {
      document.getElementById("question").innerText = "🎉 Quiz Finished!";
      document.getElementById("options").innerHTML = "";
      document.getElementById("score").innerText = "Your Score: " + score + "/" + questions.length;
      document.querySelector("button").style.display = "none"; // hide button
    }
  }

  // Function to check answer
  function checkAnswer() {
    let selected = document.querySelector('input[name="option"]:checked');
    if(!selected){
      document.getElementById("result").innerText = "⚠️ Please select an option!";
      return;
    }
    if(selected.value === questions[index].a){
      document.getElementById("result").innerText = "✅ Correct!";
      score++;
    } else {
      document.getElementById("result").innerText = "❌ Wrong! Answer: " + questions[index].a;
    }
    index++;
    setTimeout(loadQuestion, 1000);
  }

  // Start quiz
  loadQuestion();