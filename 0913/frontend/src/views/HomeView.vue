<script setup>
import LineChart from "@/components/LineChart.vue";
// import dataLab from "../utils/api.js";
import { useChartStore } from "@/stores/chart.js";
import UserForm from "@/components/UserForm.vue";

// async function getData() {
//   try {
//     const response = await dataLab.get();
//     console.log(response);
//   } catch (error) {
//     console.log(error);
//   }
// }

const chartStore = useChartStore();

chartStore.makeChart();
</script>

<template>
  <LineChart />
  <UserForm />
</template>
