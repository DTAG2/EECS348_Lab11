function update_styles() {
    let brr = document.getElementById("brr").value;
    let brg = document.getElementById("brg").value;
    let brb = document.getElementById("brb").value;
    let width = document.getElementById("width").value;
    
    let br = document.getElementById("br").value;
    let bg = document.getElementById("bg").value;
    let bb = document.getElementById("bb").value;

    let para = document.getElementById("para");

    para.style.setProperty("border-color", `rgb(${brr},${brg},${brb})`);

    para.style.setProperty("border-width", `${width}px`);

    para.style.setProperty("background-color", `rgb(${br},${bg},${bb})`);
}

function verifyPassword(){
    let p1 = document.getElementById("pass1").value;
    let p2 = document.getElementById("pass2").value;

    if (p1.length < 8 || p2.length < 8){
        alert("At least one of your passwords is less than 8 characters")
    }
    else if (p1 !== p2){
        alert("Passwords don't match")
    }
    else{
        alert("Passwords match")
    }
}