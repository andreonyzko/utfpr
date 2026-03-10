const menuBtn = document.querySelector("svg#menu");
const nav = document.querySelector("nav");

menuBtn.addEventListener('click', e => {
    nav.classList.toggle('showNav');
})