<script setup>
import { ref } from "vue";

const url = ref("https://www.naver.com/");

function setUrlNaver() {
  url.value = "https://www.naver.com";
}
function setUrlGoogle() {
  url.value = "https://www.google.co.kr";
}

const selectedColor = ref("black");
</script>

<template>
  <div>aa</div>
  <div>aa</div>
  <div>
    <a :href="url">네이버로 이동</a>

    <!-- 버튼 클릭시 url 변경 -->
    <button @click="setUrlNaver">네이버</button>
    <button @click="setUrlGoogle">구글</button>

    <hr />
    <h1 :style="{ color: selectedColor }">color</h1>
  </div>
</template>

<style scoped></style>
