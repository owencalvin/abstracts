import express from "express";
import mongoose from "mongoose";
import config from "./config";
import { Pizza } from "./pizza.model";

const app = express();

app.get("/pizzas", async (req, res) => {
    res.header("Access-Control-Allow-Origin", "*");
    res.json(await Pizza.find());
});

mongoose.connect(config.MONGODB_CONNECTION_URL).then(async () => {
    await Pizza.deleteMany({});
    await new Pizza({
        name: "Margarita",
        price: 10.0,
        ingredients: [ "Tomatto", "Mozarella", "Origan" ]

    }).save();
    await new Pizza({
        name: "Not a pizza",
        price: 14.0,
        ingredients: [ "Tomatto", "Pineapple", "Mozarella" ]
    }).save();
    await new Pizza({
        name: "Pizza Pesto",
        price: 13,
        ingredients: [ "Pesto", "Mozarella" ]

    }).save();
    app.listen(config.SERVER_PORT, () => {
        console.log(`Server listening on port ${config.SERVER_PORT}`);
    });
}).catch((err) => {
    console.error(err);
})

