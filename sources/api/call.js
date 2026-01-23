// GET 
fetch("url", {
    method: "GET",
    headers: {
        "Content-Type": "application/json",
    }
}).then(res => {
    if(!res.ok) {
        throw new Error(`HTTP error: ${res.status}`);
    }
    return res.json();
}).then(data => {})
.catch(err => console.error(err));

// POST with JSON body + headers
fetch("url", {
    method: "POST",
    headers: {
        "Content-Type": "application/json",
    },
    body: JSON.stringify({
        name: "TestUser",
    }),
}).then(res => {
    if(!res.ok) {
        throw new Error(`HTTP error: ${res.status}`);
    }
    return res.json();
}).then(data => {})
.catch(err => console.error(err));

// POST with FORM body + headers
const form = new FormData();
form.append("name", "TestUser");
fetch("url", {
    method: "POST",
    headers: {
        "Content-Type": "application/json",
    },
    body: form,
}).then(res => {
    if(!res.ok) {
        throw new Error(`HTTP error: ${res.status}`);
    }
    return res.json();
}).then(data => {})
.catch(err => console.error(err));

// API Calls with Thread Pool
const poolSize = 8;
async function worker() {}
const workers = Array.from({length: poolSize}, worker);
Promise.all(workers).then(results => {
    console.log(results);
}).catch(err => console.error(err));

