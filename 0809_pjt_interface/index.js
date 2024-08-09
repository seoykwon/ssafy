// 시간을 표시하는 함수를 만든다.
function updateTime() {
  const now = new Date();
  let hour = now.getHours();
  const minutes = String(now.getMinutes()).padStart(2, "0");
  const ampm = hour > 12 ? "PM" : "AM";
  hour = hour % 12; // 시간을 12시간으로 표시
  hour = hour ? hour : 12; // 0시를 12시로 바꿔주는 작업
  const currentTime = `${hour}:${minutes} ${ampm}`;
  const currentTimeTag = document.querySelector("#current-time");
  currentTimeTag.textContent = currentTime;
}

updateTime();
setInterval(updateTime, 1000);
