<script setup>
import { useRoute, useRouter } from "vue-router";
// useRouter -> 라우터 이동관련
// useRouter -> 해당 라우터에 정보 관련
const route = useRoute();
console.log(route);
</script>

<template>
  게시판 상세입니다.

  <h1>{{ route.params.id }} 번글입니다.</h1>
</template>

<style scoped></style>
