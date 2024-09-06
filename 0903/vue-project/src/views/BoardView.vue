<script setup>
import { useRouter } from "vue-router";
const router = useRouter();

function goDetail() {
  // router.push("/board/1");
  router.push({
    name: "boardDetail",
    params: {
      id: "1",
    },
  });
}
</script>

<template>
  게시판입니다.

  <button @click="goDetail">1번 페이지</button>
</template>

<style scoped></style>
