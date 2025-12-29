function finaloutput() {
    let htmlcode = document.getElementById("html-input").value;
    let csscode = document.getElementById("css-input").value;
    let jscode = document.getElementById("js-input").value;
    let outputcode = document.getElementById("codeExecutionOutput");
    outputcode.contentDocument.body.innerHTML = `${htmlcode}`;
    outputcode.contentDocument.head.innerHTML = `<style>${csscode}</style>`;
    outputcode.contentWindow.eval(jscode);
}
function toggleTheme() {
    let checkboxdocument = document.getElementsByClassName("form-check-input")[0];
    if (checkboxdocument.checked) {
        document.getElementById("themeToggle").setAttribute("data-bs-theme", "light");
        document.getElementById("navSwitchtext").innerHTML = '<i class="bi bi-moon"></i>';
        document.body.style.backgroundColor = "white";
        document.getElementsByTagName("section")[0].setAttribute("class", "py-5 bg-light");
        document.getElementsByTagName("nav")[0].setAttribute("class", "navbar navbar-expand-lg bg-body-tertiary");

    }
    else {
        document.getElementById("themeToggle").setAttribute("data-bs-theme", "dark");
        document.getElementById("navSwitchtext").innerHTML = '<i class="bi bi-brightness-high"></i>';
      
        document.getElementsByTagName("section")[0].setAttribute("class", "py-5 bg-light");
        document.getElementsByTagName("nav")[0].setAttribute("class", "navbar navbar-expand-lg bg-body-tertiary");
        
    }



}