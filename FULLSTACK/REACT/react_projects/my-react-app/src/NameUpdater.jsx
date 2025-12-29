import React, { useState } from 'react';

function NameUpdater() {
    const [name, setName] = useState("");  // Step 1: empty string as initial state
    const [subject, setSubject] = useState("");

    const handleChangeName = (event) => {      // Step 2: function to handle input
        setName(event.target.value);
        // update state with current input value
    };
    const handleSubjectChange = (event) => {
        setSubject(event.target.value);
    }
    const handleChange = (setter) => (event) => {
        setter(event.target.value);
    };

    return (
        <div style={{ textAlign: "center", marginTop: "50px" }}>
             <input type="text"   placeholder="Enter Favourite subject"  value={name} onChange={handleChange(setName)} />
            <h2>Type your Favourite Subject below 👇</h2>  <input value={subject} onChange={handleChange(setSubject)} />
            <h3>Hello, {name ? name : "Stranger"} 👋 ,Your Favourite subject is {subject ? subject : "AI"}</h3>
            <h2>Type your name below 👇</h2>

            {/* Step 3: Input box with onChange */}
            <input
                type="text"
                value={name}
                onChange={handleChangeName}
                placeholder="Enter your name:"
                style={{ padding: "8px", borderRadius: "5px" }}
            />
            <h2>Type your Favourite Subject below 👇</h2>

            {/* Step 3: Input box with onChange */}
            <input
                type="text"
                value={subject}
                onChange={handleSubjectChange}
                placeholder="Enter Favourite subject name:"
                style={{ padding: "8px", borderRadius: "5px" }}
            />

            {/* Step 4: Display updated name */}
            <h3>Hello, {name ? name : "Stranger"} 👋 ,Your Favourite subject is {subject ? subject : "ChatGPT"}</h3>
           
        </div>
    );
}
export default NameUpdater;