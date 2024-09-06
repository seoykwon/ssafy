<script setup>
import { ref } from "vue";
const isActive = ref(false);
const menus = ref([
  { id: 1, name: "짜장면" },
  { id: 2, name: "짬뽕" },
  { id: 3, name: "탕수육" },
]);
</script>

<template>
  <button @click="isActive = !isActive">토글</button>
  <div v-if="isActive">짠</div>
  <div v-else>안보임</div>

  <hr />

  <ul>
    <!-- 변수 in 배열 -->
    <li v-for="menu in menus" :key="menu.id">{{ menu.name }}</li>
  </ul>
</template>

<style scoped></style>
