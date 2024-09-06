<script setup>
import { RouterLink, RouterView, useRouter } from "vue-router";
// import HelloWorld from "./components/HelloWorld.vue";
import { ref } from "vue";
const router = useRouter();
// let aa = "asddas";

// const test = ref("aa");
// test.value = "Bb";
function goToBoardRoute() {
  console.log(router);
  //router.push(경로)
  //router.push("/board");
  router.push({ name: "board" });
}
</script>

<template>
  <header>
    <nav>
      <!-- {{ aa }}
      {{ test }}
      <a href="aaasdasasaaaaaaaaaaa">aa</a>
      <div :class="test">test</div>
      <input v-model="test" /> -->
      <!-- 일반 a 태그는 새로고침이 발생 -->
      <!-- <RouterLink to="/">Home</RouterLink>
      <RouterLink to="/about">About</RouterLink> -->
      <RouterLink :to="{ name: 'home' }">Home</RouterLink>

      <button @click="goToBoardRoute">게시판으로 가자</button>
    </nav>
  </header>

  <RouterView />
</template>

<style scoped></style>
