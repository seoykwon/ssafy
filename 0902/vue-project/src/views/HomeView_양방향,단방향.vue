<script setup>
import { ref } from "vue";
const message = ref("글자를 지워보자");

function onChangeText(e) {
  console.log(e);
  message.value = e.target.value;
}
</script>

<template>
  {{ message }}
  <input type="text" v-model="message" />
  <!-- <input type="text" v-bind:value> -->
  <input type="text" :value="message" />
</template>

<style scoped></style>
