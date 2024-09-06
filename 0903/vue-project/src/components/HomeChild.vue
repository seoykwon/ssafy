<script setup>
import GrandChild from "@/components/GrandChild.vue";

// 받기
const props = defineProps({
  nameProp: String,
  ageProp: Number,
});

// emit 부모에게 (메인 데이터가 있는 HomeView에게 변경 요청하기)
const emit = defineEmits(["emitTest"]);

function changeName() {
  emit("emitTest", "짜잔");
}
</script>

<template>
  <h1>HomeChild</h1>
  {{ nameProp }}
  {{ ageProp }}

  <button @click="changeName">부모에게 요청하기</button>
  <GrandChild :nameProp="nameProp"></GrandChild>
</template>

<stype scoped></stype>
