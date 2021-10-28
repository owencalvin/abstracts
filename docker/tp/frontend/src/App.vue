<template>
  <div>
    <h1>Pizzas 🍕</h1>
    <div v-if="pizzas">
      <div class="pizza" v-for="pizza in pizzas" :key="pizza._id">
        <div class="title">
          <h2>{{pizza.name}}</h2>
          <div>{{pizza.price}} CHF</div>
        </div>
        <div class="ingredients">
          <div v-for="ingredient in pizza.ingredients" :key="ingredient">{{ingredient}}</div>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
import HelloWorld from "./components/HelloWorld.vue";
import axios from "axios";

export default {
  name: 'App',
  data() {
    return {
      pizzas: null
    }
  },
  components: {
    HelloWorld
  },
  async mounted() {
    try {
      const BASE_URL = "http://localhost:8080";
      const {data} = await axios.get(`${BASE_URL}/pizzas`);
      this.pizzas = data;
    }
    catch (err) {
      console.error(err);
    }
  }
}
</script>

<style>
#app {
  max-width: 600px;
  padding: 16px;
  margin: 0 auto;
  font-family: sans-serif;
  color: #3C3C3C;
}
.pizza {
  border-radius: 12px;
  background: white;
  padding: 12px;
  margin: 12px 0;
  border: 1px solid #CCC;
}

.title {
  display: flex;
  align-items: center;
  border-bottom: 1px solid #CCCCCC;
  margin-bottom: 12px;
  padding-bottom: 12px;
}

.title h2 {
  flex: 1
}

.title > div {
  font-size: 2em;
  font-weight: bold;
}

.pizza .ingredients {
  display: flex;
  gap: 4px;
}

.pizza .ingredients > div{
  padding: 8px;
  border-radius: 9999px;
  color: white;
  background: steelblue;
}
</style>
