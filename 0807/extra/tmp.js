const url = "https://jsonplaceholder.typicode.com/users/1";


// RestAPI: GET PUT DELETE POST

// try - catch - finally

// Promise: pending / done 상태 가지는 놈
// fetch(url)
//     .then((result) => result.json())
//     .then(console.log);

async function run(){
    console.log("#1");
    const fetchResult = await fetch(url); //Promise
    console.log(fetchResult);
    console.log("#2");
    const jsonResult = await fetchResult.json();
    console.log(jsonResult);
    console.log("#3");
}
run();


const url1 = () => `https://sample.com`;
const url2 = (userId) => `https://sample.com/id=${userId}`;
const url3 = (userName) => `https://sample.com/name=${userName}`;


// let a;
//let b;
// setTimeout(() => {
    // a = 어쩌고
    // setTimeout((a) => {
        // b = 어쩌고
        // setTimeout(() => {
        // setTimeout(() => {
            // console.log("2");
        // }, 2000);
    // }, 10000);
// }, 500);
// 
// fetch().then().then().then()


const result1 = await fetch(url()); // {userId: 1}
const result2 = await fetch(url2(result1.userId)) //{userName: "ksy"}
const result3 = await fetch(url3(result2.userName));

//함수

const url21 = "https://sample.com/a"; // userid 
const url22 = "https://sample.com/b"; // username
const url23 = "https://sample.com/c"; // userpw
const result21 = await fetch(url21); //5초
const result22 = await fetch(url22); //2초
const result23 = await fetch(url23); //1초
// => 8초
const result31 = fetch(url21).then(()=>{/* 화면 업데이트*/}); //5초
const result32 = fetch(url22).then(()=>{/* 화면 업데이트*/}); //2초
const result33 = fetch(url23).then(()=>{/* 화면 업데이트*/}); //1초
// => 5초
Promise.all([result31,result32,result33]).then(()=>{console.log("전부 끝")});
Promise.any([result31,result32,result33]).then(()=>{console.log("하나 끝")});

fetch(url,{method:"get"}).then(res=>res.json()).then(...)
axios.get(url).then(...)


<style>
    div {
        background:white;
    }

    .container {
        background:tomato;
    }

    #name {
        font-weight: bold;
    }
</style>



document.getElementById("name");
document.querySelector("#name");

document.getElementsByClassName("container");
document.querySelectorAll(".container");

document.getElementsByTagName("div");
document.querySelectorAll("div");

document.querySelectorAll("div")[0];
document.querySelector("div");
$("div")