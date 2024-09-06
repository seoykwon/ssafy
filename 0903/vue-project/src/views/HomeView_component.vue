<script setup>
import HomeHeader from "@/components/HomeHeader.vue";
import HomeMain from "@/components/HomeMain.vue";
import HomeFooter from "@/components/HomeFooter.vue";
</script>

<template>
  <h1>Home</h1>
  <HomeHeader>
    <!-- aaa 이걸하고 싶다 -> 슬롯이라는 개념 배우기 -->
  </HomeHeader>
  <HomeMain> </HomeMain>
  <HomeFooter></HomeFooter>
</template>

<stype scoped></stype>
