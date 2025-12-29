let count = 0; // serial number count

function noteadd() {
    count++;

    // topic select করা
    let topic = document.getElementById("topic").value;

    // textarea এর value নেয়া
    let textarea = document.querySelector("textarea").value;

    if (textarea.trim() === "") {
        alert("Please write something before adding!");
        return;
    }
    // টেবিল ধরতে হবে
    let table = document.querySelector("table");
    // নতুন row create
    let row = table.insertRow(-1);


    let cell1 = row.insertCell(0);
    let cell2 = row.insertCell(1);
    let cell3 = row.insertCell(2);
    let cell4 = row.insertCell(3);
    let cell5 = row.insertCell(4);
     let cell6 = row.insertCell(5);
    cell1.innerText = count;
    cell2.innerText = topic;
    cell3.innerText = textarea;
    cell4.innerHTML = `<button class="edit-btn" onclick="edit(this)"><i class="bi bi-pencil-square"></i></button>`;
    cell5.innerHTML = `<button onclick="deletenote(this)"><i class="bi bi-trash" ></i></button>`;
     cell6.innerHTML = `<button onclick="viewnote(this)" ><i class="bi bi-eye" ></i></button>`;
    document.querySelector("textarea").value = "";
}
function deletenote(btn) {
    let row = btn.closest("tr");
    row.remove();
}
function save(btn) {
    let row = btn.closest('tr');
    let cells = row.getElementsByTagName('td');
    let topic = document.getElementById('editedtopic').value;
    let notes = document.getElementById('notes').value;
    cells[1].innerText=topic;
    cells[2].innerText=notes;
    cells[3].innerHTML = `<button class="edit-btn" onclick="edit(this)"><i class="bi bi-pencil-square"></i></button>`;
}
function edit(btn) {
    let row = btn.closest('tr');
    let cells = row.getElementsByTagName('td');
    let topic = cells[1].innerText;
    cells[1].innerHTML = `<select id="editedtopic" name="topic">
            <option value="math" ${topic === 'math' ? 'selected' : ''} id="Math">Math</option>
            <option value="html" ${topic === 'html' ? 'selected' : ''} id="html">html</option>
            <option value="science"${topic === 'science' ? 'selected' : ''} id="science">science</option>
            <option value="English" ${topic === 'English' ? 'selected' : ''}id="English">English</option>
        </select>`;
    let notes = cells[2].innerText;
    cells[2].innerHTML = `<textarea id='notes' placeholder="Type Your Notes..">${notes}</textarea>`;
    cells[3].innerHTML = `<button id='done' onclick="save(this)"><i class="bi bi-check"></button>`;


}