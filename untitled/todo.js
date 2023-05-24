const addToDoButton = document.getElementById('addToDoBtn');
const toDoContainer = document.getElementById('toDoContainer');
const inputField = document.getElementById('inputField');

addToDoButton.addEventListener('click',function (){
    const paragraph = document.createElement("p");
    paragraph.classList.add('paragraph-styling');
    paragraph.innerText=inputField.value;
    toDoContainer.appendChild(paragraph);
    inputField.value = '';
    paragraph.addEventListener("click", function (){
        paragraph.style.textDecoration = "line-through";
    })
    paragraph.addEventListener("dblclick", function (){
        toDoContainer.removeChild(paragraph);
    })



})