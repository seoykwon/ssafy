<script setup>
import { ref } from "vue";
import HomeChild from "@/components/HomeChild.vue";

const name = ref("david");
const age = ref(10);

function changeName(n) {
  console.log(n);
  name.value = n;
  console.log("왔냐");
}
</script>

<template>
  <h1>Home</h1>

  <div>{{ name }}</div>
  <div>{{ age }}</div>

  <!-- props -> 부모에서 자식으로 데이터 전달 -->
  <!-- 넘길 키값= 실제로 넘어가는 값 -->
  <!-- <HomeChild :nameProp="name" :ageProp="age"></HomeChild> -->
  <HomeChild @emitTest="changeName" :nameProp="name" :ageProp="age"></HomeChild>
</template>

<stype scoped></stype>
