export default {
    SERVER_PORT: Number(process.env.SERVER_PORT || 8080),
    MONGODB_CONNECTION_URL: process.env.MONGODB_CONNECTION_URL || "mongodb://localhost:27017/pizzas"
}