/** help: https://expressjs.com/en/resources/middleware/cors.html */
var express = require("express");
var cors = require("cors");
let app = express();

var corsOptions = { origin: null };
app.get("/", cors(), (req: any, res: any, next: any) => { });
app.listen(500, () => { });
