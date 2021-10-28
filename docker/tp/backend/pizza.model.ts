import Mongoose from "mongoose";

const schema = new Mongoose.Schema({
    name: String,
    price: Number,
    ingredients: [ String ]
});

export const Pizza = Mongoose.model("Pizza", schema);
